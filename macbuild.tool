#!/bin/bash

package() {
  if [ ! -d "$1" ]; then
    echo "Missing package directory $1"
    exit 1
  fi

  local ver
  ver="1.0"
  if [ "$ver" = "" ]; then
    echo "Invalid version $ver"
    ver="UNKNOWN"
  fi

  selfdir=$(pwd)
  pushd "$1" || exit 1
  rm -rf tmp || exit 1

  # Switch to parent architecture directory (i.e. Build/X64 -> Build).
  local dstdir
  dstdir="$(pwd)/tmp"
  pushd .. || exit 1

  for arch in "${ARCHS[@]}"; do
    mkdir -p "${dstdir}/${arch}" || exit 1

    # copy DXE drivers.
    cp "${arch}/*.efi" "${dstdir}/${arch}" || exit 1
  done

  pushd "${dstdir}" || exit 1
  zip -qr -FS ../"AmdXnuSupportPkg-${ver}-${2}.zip" ./* || exit 1
  popd || exit 1
  rm -rf "${dstdir}" || exit 1

  popd || exit 1
  popd || exit 1
}

cd "$(dirname "$0")" || exit 1
if [ "$ARCHS" = "" ]; then
  ARCHS=(X64)
  export ARCHS
fi
SELFPKG=AmdXnuSupportPkg
NO_ARCHIVES=0
DEPNAMES=('OpenCorePkg')
DEPURLS=('https://github.com/acidanthera/OpenCorePkg')
DEPBRANCHES=('master')

export SELFPKG
export NO_ARCHIVES
export DEPNAMES
export DEPURLS
export DEPBRANCHES

src=$(curl -Lfs https://raw.githubusercontent.com/acidanthera/ocbuild/master/efibuild.sh) && eval "$src" || exit 1
