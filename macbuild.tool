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

    # copy OpenCore main program.
    ls "${arch}"
    cp "${arch}/OpenCore.efi" "${dstdir}/${arch}/EFI/OC" || exit 1

    local suffix="${arch}"
    if [ "${suffix}" = "X64" ]; then
      suffix="x64"
    fi
    cp "${arch}/Bootstrap.efi" "${dstdir}/${arch}/EFI/BOOT/BOOT${suffix}.efi" || exit 1
    cp "${ocflavour}" "${dstdir}/${arch}/EFI/BOOT" || exit 1

    efiTools=(
      "BootKicker.efi"
      "ChipTune.efi"
      "CleanNvram.efi"
      "CsrUtil.efi"
      "GopStop.efi"
      "KeyTester.efi"
      "MmapDump.efi"
      "ResetSystem.efi"
      "RtcRw.efi"
      "TpmInfo.efi"
      "OpenControl.efi"
      "ControlMsrE2.efi"
      )
    for efiTool in "${efiTools[@]}"; do
      cp "${arch}/${efiTool}" "${dstdir}/${arch}/EFI/OC/Tools"/ || exit 1
    done

    # Special case: OpenShell.efi
    cp "${arch}/Shell.efi" "${dstdir}/${arch}/EFI/OC/Tools/OpenShell.efi" || exit 1

    efiDrivers=(
      "HiiDatabase.efi"
      "NvmExpressDxe.efi"
      "AudioDxe.efi"
      "CrScreenshotDxe.efi"
      "OpenCanopy.efi"
      "OpenPartitionDxe.efi"
      "OpenRuntime.efi"
      "OpenUsbKbDxe.efi"
      "Ps2MouseDxe.efi"
      "Ps2KeyboardDxe.efi"
      "UsbMouseDxe.efi"
      "OpenHfsPlus.efi"
      "XhciDxe.efi"
      )
    for efiDriver in "${efiDrivers[@]}"; do
      cp "${arch}/${efiDriver}" "${dstdir}/${arch}/EFI/OC/Drivers"/ || exit 1
    done
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
