## @file
# AMD XNU support Package
#
# Copyright (C) 2018, Download-Fritz.  All rights reserved.<BR>
#
#    This program and the accompanying materials
#    are licensed and made available under the terms and conditions of the BSD License
#    which accompanies this distribution. The full text of the license may be found at
#    http://opensource.org/licenses/bsd-license.php
#
#    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
##

[Defines]
  PLATFORM_NAME           = AmdXnuSupportPkg
  PLATFORM_GUID           = F5849560-95C7-42D4-B24E-26527E3C3248
  PLATFORM_VERSION        = 1.0
  SUPPORTED_ARCHITECTURES = X64
  BUILD_TARGETS           = RELEASE|DEBUG|NOOPT
  SKUID_IDENTIFIER        = DEFAULT
  DSC_SPECIFICATION       = 0x00010006

[LibraryClasses]
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  CpuLib|MdePkg/Library/BaseCpuLib/BaseCpuLib.inf
  CpuExceptionHandlerLib|MdeModulePkg/Library/CpuExceptionHandlerLibNull/CpuExceptionHandlerLibNull.inf
  DebugLib|MdePkg/Library/BaseDebugLibNull/BaseDebugLibNull.inf
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf
  LocalApicLib|UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib.inf

[LibraryClasses.common.DXE_DRIVER]
  BaseMemoryLib|MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr.inf
  BaseRngLib|MdePkg/Library/BaseRngLib/BaseRngLib.inf
  BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf
  DebugLib|OpenCorePkg/Library/OcDebugLogLib/OcDebugLogLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  MtrrLib|UefiCpuPkg/Library/MtrrLib/MtrrLib.inf
  DxeServicesTableLib|MdePkg/Library/DxeServicesTableLib/DxeServicesTableLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  FrameBufferBltLib|MdeModulePkg/Library/FrameBufferBltLib/FrameBufferBltLib.inf
  HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
  OrderedCollectionLib|MdePkg/Library/BaseOrderedCollectionRedBlackTreeLib/BaseOrderedCollectionRedBlackTreeLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  OcAcpiLib|OpenCorePkg/Library/OcAcpiLib/OcAcpiLib.inf
  OcAfterBootCompatLib|OpenCorePkg/Library/OcAfterBootCompatLib/OcAfterBootCompatLib.inf
  OcApfsLib|OpenCorePkg/Library/OcApfsLib/OcApfsLib.inf
  OcAppleBootPolicyLib|OpenCorePkg/Library/OcAppleBootPolicyLib/OcAppleBootPolicyLib.inf
  OcAppleChunklistLib|OpenCorePkg/Library/OcAppleChunklistLib/OcAppleChunklistLib.inf
  OcAppleDiskImageLib|OpenCorePkg/Library/OcAppleDiskImageLib/OcAppleDiskImageLib.inf
  OcAppleEventLib|OpenCorePkg/Library/OcAppleEventLib/OcAppleEventLib.inf
  OcAppleImageConversionLib|OpenCorePkg/Library/OcAppleImageConversionLib/OcAppleImageConversionLib.inf
  OcAppleImg4Lib|OpenCorePkg/Library/OcAppleImg4Lib/OcAppleImg4Lib.inf
  OcAppleKernelLib|OpenCorePkg/Library/OcAppleKernelLib/OcAppleKernelLib.inf
  OcAppleKeyMapLib|OpenCorePkg/Library/OcAppleKeyMapLib/OcAppleKeyMapLib.inf
  OcAppleKeysLib|OpenCorePkg/Library/OcAppleKeysLib/OcAppleKeysLib.inf
  OcAppleRamDiskLib|OpenCorePkg/Library/OcAppleRamDiskLib/OcAppleRamDiskLib.inf
  OcAppleSecureBootLib|OpenCorePkg/Library/OcAppleSecureBootLib/OcAppleSecureBootLib.inf
  OcAppleUserInterfaceThemeLib|OpenCorePkg/Library/OcAppleUserInterfaceThemeLib/OcAppleUserInterfaceThemeLib.inf
  OcAudioLib|OpenCorePkg/Library/OcAudioLib/OcAudioLib.inf
  OcBlitLib|OpenCorePkg/Library/OcBlitLib/OcBlitLib.inf
  OcBootManagementLib|OpenCorePkg/Library/OcBootManagementLib/OcBootManagementLib.inf
  OcBootServicesTableLib|OpenCorePkg/Library/OcBootServicesTableLib/OcBootServicesTableLib.inf
  OcCompressionLib|OpenCorePkg/Library/OcCompressionLib/OcCompressionLib.inf
  OcConfigurationLib|OpenCorePkg/Library/OcConfigurationLib/OcConfigurationLib.inf
  OcConsoleControlEntryModeGenericLib|OpenCorePkg/Library/OcConsoleControlEntryModeLib/OcConsoleControlEntryModeGenericLib.inf
  OcConsoleControlEntryModeLocalLib|OpenCorePkg/Library/OcConsoleControlEntryModeLib/OcConsoleControlEntryModeLocalLib.inf
  OcConsoleLib|OpenCorePkg/Library/OcConsoleLib/OcConsoleLib.inf
  OcCpuLib|OpenCorePkg/Library/OcCpuLib/OcCpuLib.inf
  OcCryptoLib|OpenCorePkg/Library/OcCryptoLib/OcCryptoLib.inf
  OcDataHubLib|OpenCorePkg/Library/OcDataHubLib/OcDataHubLib.inf
  OcDebugLogLib|OpenCorePkg/Library/OcDebugLogLib/OcDebugLogLib.inf
  OcDeviceMiscLib|OpenCorePkg/Library/OcDeviceMiscLib/OcDeviceMiscLib.inf
  OcDevicePathLib|OpenCorePkg/Library/OcDevicePathLib/OcDevicePathLib.inf
  OcDevicePropertyLib|OpenCorePkg/Library/OcDevicePropertyLib/OcDevicePropertyLib.inf
  OcDeviceTreeLib|OpenCorePkg/Library/OcDeviceTreeLib/OcDeviceTreeLib.inf
  OcDriverConnectionLib|OpenCorePkg/Library/OcDriverConnectionLib/OcDriverConnectionLib.inf
  OcFileLib|OpenCorePkg/Library/OcFileLib/OcFileLib.inf
  OcFirmwarePasswordLib|OpenCorePkg/Library/OcFirmwarePasswordLib/OcFirmwarePasswordLib.inf
  OcFirmwareVolumeLib|OpenCorePkg/Library/OcFirmwareVolumeLib/OcFirmwareVolumeLib.inf
  OcGuardLib|OpenCorePkg/Library/OcGuardLib/OcGuardLib.inf
  OcHashServicesLib|OpenCorePkg/Library/OcHashServicesLib/OcHashServicesLib.inf
  OcHdaDevicesLib|OpenCorePkg/Library/OcHdaDevicesLib/OcHdaDevicesLib.inf
  OcHeciLib|OpenCorePkg/Library/OcHeciLib/OcHeciLib.inf
  OcHiiDatabaseLocalLib|OpenCorePkg/Library/OcHiiDatabaseLib/OcHiiDatabaseLocalLib.inf
  OcInputLib|OpenCorePkg/Library/OcInputLib/OcInputLib.inf
  OcMachoLib|OpenCorePkg/Library/OcMachoLib/OcMachoLib.inf
  OcMacInfoLib|OpenCorePkg/Library/OcMacInfoLib/OcMacInfoLib.inf
  OcMainLib|OpenCorePkg/Library/OcMainLib/OcMainLib.inf
  OcMemoryLib|OpenCorePkg/Library/OcMemoryLib/OcMemoryLib.inf
  OcMiscLib|OpenCorePkg/Library/OcMiscLib/OcMiscLib.inf
  OcMp3Lib|OpenCorePkg/Library/OcMp3Lib/OcMp3Lib.inf
  OcOSInfoLib|OpenCorePkg/Library/OcOSInfoLib/OcOSInfoLib.inf
  OcPngLib|OpenCorePkg/Library/OcPngLib/OcPngLib.inf
  OcRngLib|OpenCorePkg/Library/OcRngLib/OcRngLib.inf
  OcRtcLib|OpenCorePkg/Library/OcRtcLib/OcRtcLib.inf
  OcSerializeLib|OpenCorePkg/Library/OcSerializeLib/OcSerializeLib.inf
  OcSmbiosLib|OpenCorePkg/Library/OcSmbiosLib/OcSmbiosLib.inf
  OcSmcLib|OpenCorePkg/Library/OcSmcLib/OcSmcLib.inf
  OcStorageLib|OpenCorePkg/Library/OcStorageLib/OcStorageLib.inf
  OcStringLib|OpenCorePkg/Library/OcStringLib/OcStringLib.inf
  OcTemplateLib|OpenCorePkg/Library/OcTemplateLib/OcTemplateLib.inf
  OcTypingLib|OpenCorePkg/Library/OcTypingLib/OcTypingLib.inf
  TimerLib|OpenCorePkg/Library/OcTimerLib/OcTimerLib.inf
  OcUnicodeCollationEngGenericLib|OpenCorePkg/Library/OcUnicodeCollationEngLib/OcUnicodeCollationEngGenericLib.inf
  OcUnicodeCollationEngLocalLib|OpenCorePkg/Library/OcUnicodeCollationEngLib/OcUnicodeCollationEngLocalLib.inf
  OcVirtualFsLib|OpenCorePkg/Library/OcVirtualFsLib/OcVirtualFsLib.inf
  OcWaveLib|OpenCorePkg/Library/OcWaveLib/OcWaveLib.inf
  OcXmlLib|OpenCorePkg/Library/OcXmlLib/OcXmlLib.inf
  OcPeCoffExtLib|OpenCorePkg/Library/OcPeCoffExtLib/OcPeCoffExtLib.inf
  OcPeCoffLib|OpenCorePkg/Library/OcPeCoffLib/OcPeCoffLib.inf
  PciCf8Lib|MdePkg/Library/BasePciCf8Lib/BasePciCf8Lib.inf
  PciLib|MdePkg/Library/BasePciLibCf8/BasePciLibCf8.inf
  PlatformHookLib|MdeModulePkg/Library/BasePlatformHookLibNull/BasePlatformHookLibNull.inf
  ReportStatusCodeLib|MdePkg/Library/BaseReportStatusCodeLibNull/BaseReportStatusCodeLibNull.inf
  PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
  PerformanceLib|MdePkg/Library/BasePerformanceLibNull/BasePerformanceLibNull.inf
  SerialPortLib|MdeModulePkg/Library/BaseSerialPortLib16550/BaseSerialPortLib16550.inf
  ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  SynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  UefiUsbLib|MdePkg/Library/UefiUsbLib/UefiUsbLib.inf
  ResetSystemLib|OpenCorePkg/Library/OcResetSystemLib/OcResetSystemLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  MpInitLib|AmdXnuSupportPkg/Library/DxeMpInitLibMpService/DxeMpInitLibMpService.inf

[Components]
  AmdXnuSupportPkg/AmdIntelEmu/Dxe/AmdIntelEmuDxe.inf
  AmdXnuSupportPkg/AmdIntelEmu/Runtime/AmdIntelEmuRuntime.inf {
    <LibraryClasses>
      DebugLib|MdePkg/Library/BaseDebugLibNull/BaseDebugLibNull.inf
  }

[PcdsFixedAtBuild]
!if $(TARGET) == DEBUG
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0xFFFFFFFF
  gEfiMdePkgTokenSpaceGuid.PcdFixedDebugPrintErrorLevel|0xFFFFFFFF
!else
  # DEBUG_PRINT_ENABLED
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x02
  # DEBUG_ERROR | DEBUG_WARN
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x80000002
  gEfiMdePkgTokenSpaceGuid.PcdFixedDebugPrintErrorLevel|0x80000002
!endif

[BuildOptions]
  INTEL:*_*_*_CC_FLAGS       = /DDISABLE_NEW_DEPRECATED_INTERFACES
  MSFT:*_*_*_CC_FLAGS        = /D DISABLE_NEW_DEPRECATED_INTERFACES
  GCC:*_*_*_CC_FLAGS         = -D DISABLE_NEW_DEPRECATED_INTERFACES
  XCODE:*_*_*_CC_FLAGS       = -D DISABLE_NEW_DEPRECATED_INTERFACES
  XCODE:RELEASE_*_*_CC_FLAGS = -flto
  XCODE:DEBUG_*_*_CC_FLAGS   = -flto
