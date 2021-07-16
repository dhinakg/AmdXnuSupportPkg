#ifndef AMD_INTEL_EMU_H_
#define AMD_INTEL_EMU_H_

#include <Library/BaseLib.h>

#include "VirtualMemory.h"

#define CR0_CD  BIT30

#define PAT_WC  0x01U
#define PAT_WB  0x06U

#pragma pack (1)

#define MSR_VM_HSAVE_PA       0xC0010117U

#define MSR_VM_CR  0xC0010114U

typedef union {
  PACKED struct {
    UINT32 DPD       : 1;
    UINT32 R_INIT    : 1;
    UINT32 DIS_A20M  : 1;
    UINT32 LOCK      : 1;
    UINT32 SVMDIS    : 1;
    UINT32 Reserved1 : 27;
    UINT32 Reserved2 : 32;
  } Bits;
  UINT64 Uint64;
} MSR_VM_CR_REGISTER;

#define MSR_AMD_CPUID_EXT_FEATURES  0xC0011005U

typedef union {
  PACKED struct {
    UINT32 FPU                     : 1;
    UINT32 VME                     : 1;
    UINT32 DE                      : 1;
    UINT32 PSE                     : 1;
    UINT32 TSC                     : 1;
    UINT32 MSR                     : 1;
    UINT32 PAE                     : 1;
    UINT32 MCE                     : 1;
    UINT32 CMPXCHG8B               : 1;
    UINT32 APIC                    : 1;
    UINT32 Reserved1               : 1;
    UINT32 SysCallSysRet           : 1;
    UINT32 MTRR                    : 1;
    UINT32 PGE                     : 1;
    UINT32 MCA                     : 1;
    UINT32 CMOV                    : 1;
    UINT32 PAT                     : 1;
    UINT32 PSE36                   : 1;
    UINT32 Reserved2               : 2;
    UINT32 NX                      : 1;
    UINT32 Reserved3               : 1;
    UINT32 MmxExt                  : 1;
    UINT32 MMX                     : 1;
    UINT32 FXSR                    : 1;
    UINT32 Page1GB                 : 1;
    UINT32 RDTSCP                  : 1;
    UINT32 Reserved4               : 1;
    UINT32 LM                      : 1;
    UINT32 ThreeDNowExt            : 1;
    UINT32 ThreeDNow               : 1;
    UINT32 LahfSahf                : 1;
    UINT32 CmpLegacy               : 1;
    UINT32 SVM                     : 1;
    UINT32 ExtApicSpace            : 1;
    UINT32 AltMovCr8               : 1;
    UINT32 ABM                     : 1;
    UINT32 SSE4A                   : 1;
    UINT32 MisAlignSse             : 1;
    UINT32 ThreeDNowPrefetch       : 1;
    UINT32 OSVW                    : 1;
    UINT32 IBS                     : 1;
    UINT32 XOP                     : 1;
    UINT32 SKINIT                  : 1;
    UINT32 WDT                     : 1;
    UINT32 Reserved5               : 1;
    UINT32 LWP                     : 1;
    UINT32 FMA4                    : 1;
    UINT32 TCE                     : 1;
    UINT32 Reserved6               : 4;
    UINT32 TopologyExtensions      : 1;
    UINT32 PerfCtrExtDFCore        : 1;
    UINT32 PerfCtrExtDF            : 1;
    UINT32 Reserved7               : 1;
    UINT32 DataBreakpointExtension : 1;
    UINT32 PerfTsc                 : 1;
    UINT32 PerfCtrExtL3            : 1;
    UINT32 MwaitExtended           : 1;
    UINT32 Reserved8               : 2;
  }      Bits;
  UINT64 Uint64;
} MSR_AMD_CPUID_EXT_FEATURES_REGISTER;

#define MSR_AMD_HWCR  0xC0010015U

typedef union {
  PACKED struct {
    UINT32 SmmLock             : 1;
    UINT32 Reserved1           : 2;
    UINT32 TlbCacheDis         : 1;
    UINT32 INVDWBINVD          : 1;
    UINT32 Reserved2           : 2;
    UINT32 AllowFerrOnNe       : 1;
    UINT32 IgnneEm             : 1;
    UINT32 MonWaitDis          : 1;
    UINT32 MonMwaitUserEn      : 1;
    UINT32 Reserved3           : 2;
    UINT32 SmiSpCycDis         : 1;
    UINT32 Reserved4           : 2;
    UINT32 Wrap32Dis           : 1;
    UINT32 McStatusWrEn        : 1;
    UINT32 Reserved5           : 1;
    UINT32 IoCfgGpFault        : 1;
    UINT32 LockTscToCurrentP0  : 1;
    UINT32 Reserved6           : 2;
    UINT32 TscFreqSel          : 1;
    UINT32 CpbDis              : 1;
    UINT32 EffFreqCntMwait     : 1;
    UINT32 EffFreqReadOnlyLock : 1;
    UINT32 Reserved7           : 1;
    UINT32 CSEnable            : 1;
    UINT32 IRPerfEn            : 1;
    UINT32 Reserved8           : 31;
  }      Bits;
  UINT64 Uint64;
} MSR_AMD_HWCR_REGISTER;

#define MSR_AMD_PSTATE0_DEF  0xC0010064U

typedef union {
  PACKED struct {
    UINT32 CpuFid   : 8;
    UINT32 CpuDfsId : 6;
    UINT32 CpuVid   : 8;
    UINT32 IddValue : 8;
    UINT32 IddDiv   : 2;
    UINT32 Reserved : 31;
    UINT32 PstateEn : 1;
  }      Bits;
  UINT64 Uint64;
} MSR_AMD_PSTATE_DEF_REGISTER;

typedef union {
  PACKED struct {
    UINT32 SCE       : 1;
    UINT32 Reserved1 : 7;
    UINT32 LME       : 1;
    UINT32 Reserved2 : 1;
    UINT32 LMA       : 1;
    UINT32 NXE       : 1;
    UINT32 SVME      : 1;
    UINT32 LMSLE     : 1;
    UINT32 FFXSR     : 1;
    UINT32 TCE       : 1;
    UINT32 Reserved3 : 16;
    UINT32 Reserved4 : 32;
  }      Bits;
  UINT64 Uint64;
} MSR_AMD_EFER_REGISTER;

#define CPUID_AMD_APIC_ID_SIZE_CORE_COUNT  0x80000008U

typedef union {
  PACKED struct {
    UINT32 NC               : 8;
    UINT32 Reserved1        : 4;
    UINT32 ApicIdCoreIdSize : 4;
    UINT32 Reserved2        : 16;
  }      Bits;
  UINT32 Uint32;
} CPUID_AMD_APIC_ID_SIZE_CORE_COUNT_ECX;

#define CPUID_AMD_SVM_FEATURE_IDENTIFICATION  0x8000000AU

typedef union {
  PACKED struct {
    UINT32 NP                   : 1;
    UINT32 LbrVirt              : 1;
    UINT32 SVML                 : 1;
    UINT32 NRIPS                : 1;
    UINT32 TscRateMsr           : 1;
    UINT32 VmcbClean            : 1;
    UINT32 FlushByAsid          : 1;
    UINT32 DecodeAssists        : 1;
    UINT32 Reserved1            : 2;
    UINT32 PauseFilter          : 1;
    UINT32 Reserved2            : 1;
    UINT32 PauseFilterThreshold : 1;
    UINT32 Reserved3            : 9;
  }      Bits;
  UINT32 Uint32;
} CPUID_AMD_SVM_FEATURE_IDENTIFICATION_EDX;

#define CPUID_AMD_COMPUTE_UNIT_IDENTIFIERS  0x8000001EU

typedef union {
  PACKED struct {
    UINT32 ComputeUnitId       : 8;
    UINT32 CoresPerComputeUnit : 2;
    UINT32 Reserved            : 22;
  }      Bits;
  UINT32 Uint32;
} CPUID_AMD_COMPUTE_UNIT_IDENTIFIERS_EBX;

typedef union {
  PACKED struct {
    UINT32 Type     : 4;
    UINT32 S        : 1;
    UINT32 DPL      : 2;
    UINT32 P        : 1;
    UINT32 AVL      : 1;
    UINT32 L        : 1;
    UINT32 DB       : 1;
    UINT32 G        : 1;
    UINT32 Reserved : 4;
  }      Bits;
  UINT16 Uint16;
} IA32_SEGMENT_ATTRIBUTES;

#define VMEXIT_EXCP_DB  0x0041U
#define VMEXIT_EXCP_UD  0x0046U
#define VMEXIT_EXCP_SX  0x005EU
#define VMEXIT_INIT     0x0063U
#define VMEXIT_CPUID    0x0072U
#define VMEXIT_IRET     0x0074U
#define VMEXIT_MSR      0x007CU
#define VMEXIT_VMRUN    0x0080U
#define VMEXIT_NPF      0x0400U

#define AMD_VMCB_EXCEPTION_UD  BIT6

typedef union {
  PACKED struct {
    UINT32 I        : 1;
    UINT32 IOPM     : 1;
    UINT32 ASID     : 1;
    UINT32 TPR      : 1;
    UINT32 NP       : 1;
    UINT32 CRx      : 1;
    UINT32 DRx      : 1;
    UINT32 DT       : 1;
    UINT32 SEG      : 1;
    UINT32 CR2      : 1;
    UINT32 LBR      : 1;
    UINT32 AVIC     : 1;
    UINT32 Reserved : 20;
  }      Bits;
  UINT32 Uint32;
} AMD_VMCB_CLEAN_FIELD;

STATIC_ASSERT (sizeof (AMD_VMCB_CLEAN_FIELD) == 4, "AMD_VMCB_CLEAN_FIELD is expected to be 4 bytes");

typedef enum {
  AmdVmcbIntr              = 0,
  AmdVmcbNMI               = 2,
  AmdVmcbException         = 3,
  AmdVmcbSoftwareInterrupt = 4
} AMD_VMCB_EVENTINJ_TYPE;

typedef union {
  PACKED struct {
    UINT32 VECTOR    : 8;
    UINT32 TYPE      : 3;
    UINT32 EV        : 1;
    UINT32 Reserved  : 19;
    UINT32 V         : 1;
    UINT32 ERRORCODE : 32;
  }      Bits;
  UINT64 Uint64;
} AMD_VMCB_EVENT;

STATIC_ASSERT (sizeof (AMD_VMCB_EVENT) == 8, "AMD_VMCB_EVENT is expected to be 8 bytes");

typedef union {
  PACKED struct {
    UINT32 P                 : 1;
    UINT32 RW                : 1;
    UINT32 US                : 1;
    UINT32 RSV               : 1;
    UINT32 ID                : 1;
    UINT32 Reserved1         : 27;
    UINT32 FaultFinalAddress : 1;
    UINT32 FaultGuestTlb     : 1;
    UINT32 Reserved2         : 30;
  }      Bits;
  UINT32 Uint32;
  UINT64 Uint64;
} AMD_VMCB_EXITINFO1_NPF;

typedef PACKED struct {
  UINT16 InterceptReadCr;
  UINT16 InterceptWriteCr;

  UINT16 InterceptReadDr;
  UINT16 InterceptWriteDr;

  UINT32 InterceptExceptionVectors;

  UINT32 InterceptIntr              : 1;
  UINT32 InterceptNmi               : 1;
  UINT32 InterceptSmi               : 1;
  UINT32 InterceptInit              : 1;
  UINT32 InterceptVintr             : 1;
  UINT32 InterceptCr0ExceptTsOrMp   : 1;
  UINT32 InterceptReadIdtr          : 1;
  UINT32 InterceptReadGdtr          : 1;
  UINT32 InterceptReadLdtr          : 1;
  UINT32 InterceptReadTr            : 1;
  UINT32 InterceptWriteIdtr         : 1;
  UINT32 InterceptWriteGdtr         : 1;
  UINT32 InterceptWriteLdtr         : 1;
  UINT32 InterceptWriteTr           : 1;
  UINT32 InterceptRdtsc             : 1;
  UINT32 InterceptRdpmc             : 1;
  UINT32 InterceptPushf             : 1;
  UINT32 InterceptPopf              : 1;
  UINT32 InterceptCpuid             : 1;
  UINT32 InterceptRsm               : 1;
  UINT32 InterceptIret              : 1;
  UINT32 InterceptIntn              : 1;
  UINT32 InterceptInvd              : 1;
  UINT32 InterceptPause             : 1;
  UINT32 InterceptHlt               : 1;
  UINT32 InterceptInvlpg            : 1;
  UINT32 InterceptInvlpga           : 1;
  UINT32 InterceptIoProt            : 1;
  UINT32 InterceptMsrProt           : 1;
  UINT32 InterceptTaskSwitches      : 1;
  UINT32 InterceptFerrFreeze        : 1;
  UINT32 InterceptShutdown          : 1;

  UINT32 InterceptVmrun             : 1;
  UINT32 InterceptVmmcall           : 1;
  UINT32 InterceptVmload            : 1;
  UINT32 InterceptVmsave            : 1;
  UINT32 InterceptStgi              : 1;
  UINT32 InterceptClgi              : 1;
  UINT32 InterceptSkinit            : 1;
  UINT32 InterceptRdtscp            : 1;
  UINT32 InterceptIcebp             : 1;
  UINT32 InterceptEbinvd            : 1;
  UINT32 InterceptMonitor           : 1;
  UINT32 InterceptMwait             : 1;
  UINT32 InterceptMwaitHwMon        : 1;
  UINT32 InterceptXsetbvwn          : 1;
  UINT32 Reserved1                  : 1;
  UINT32 InterceptEfer              : 1;
  UINT32 InterceptWriteCrPostFinish : 16;

  UINT8  Reserved2[40];

  UINT16 PauseFilterThreshold;
  UINT16 PauseFilterCount;
  UINT64 IOPM_BASE_PA;
  UINT64 MSRPM_BASE_PA;
  UINT64 TSC_OFFSET;

  UINT32 GuestAsid;
  UINT8  TLB_CONTROL;
  UINT8  Reserved3[3];

  UINT32 V_TPR                      : 8;
  UINT32 V_IRQ                      : 1;
  UINT32 VGIF                       : 1;
  UINT32 Reserved4                  : 6;
  UINT32 V_INTR_PRIO                : 4;
  UINT32 V_IGN_TPR                  : 1;
  UINT32 Reserved5                  : 3;
  UINT32 V_INTR_MASKING             : 1;
  UINT32 VirtualGifEnabled          : 1;
  UINT32 Reserved6                  : 5;
  UINT32 AvicEnable                 : 1;
  UINT32 V_INTR_VECTOR              : 8;
  UINT32 Reserved7                  : 24;

  UINT32 INTERRUPT_SHADOW           : 1;
  UINT32 GUEST_INTERRUPT_MASK       : 1;
  UINT32 Reserved8                  : 30;
  UINT32 Reserved9;

  UINT64 EXITCODE;
  UINT64 EXITINFO1;
  UINT64 EXITINFO2;
  AMD_VMCB_EVENT EXITINTINFO;

  UINT32 NP_ENABLE                  : 1;
  UINT32 EnableSev                  : 1;
  UINT32 EnableSevEs                : 1;
  UINT32 Reserved10                 : 29;
  UINT32 Reserved11;

  UINT64 AVIC_APIC_BASE; // The upper 12 bits must be 0.
  UINT64 Ghcb;
  AMD_VMCB_EVENT EVENTINJ;
  UINT64 N_CR3;

  UINT32 LBR_VIRTUALIZATION_ENABLE  : 1;
  UINT32 VirtualizedVmsaveVmload    : 1;
  UINT32 Reserved12                 : 30;
  UINT32 Reserved13;

  AMD_VMCB_CLEAN_FIELD VmcbCleanBits;
  UINT32 Reserved14;

  UINT64 nRIP;

  UINT8  NumberOfBytesDispatched;
  UINT8  GuestInstructionBytes[15];

  UINT64 AVIC_APIC_BACKING_PAGE; // The upper and lower 12 bits must be 0.

  UINT64 Reserved15;

  UINT64 AVIC_LOGICAL_TABLE;  // The upper 12 bits must be 0.

  // [63:52] 0
  // [51:12] Bits [51:12] of AVIC_PHYSICAL_TABLE
  // [11:8]  0
  // [7:0]   AVIC_PHYSICAL_MAX_INDEX
  UINT64 AVIC_PHYSICAL;

  UINT64 Reserved16;

  UINT64 VmcbSaveState; // The upper and lower 12 bits must be 0.

  UINT8  Reserved17[752];
} AMD_VMCB_CONTROL_AREA;

STATIC_ASSERT (sizeof (AMD_VMCB_CONTROL_AREA) == 0x400, "AMD_VMCB_CONTROL_AREA is expected to be 0x400 bytes");

typedef PACKED struct {
  UINT16 Selector;
  UINT16 Attributes;
  UINT32 Limit;
  UINT64 Base;
} AMD_VMCB_SAVE_STATE_SELECTOR;

typedef PACKED struct {
  AMD_VMCB_SAVE_STATE_SELECTOR ES;
  AMD_VMCB_SAVE_STATE_SELECTOR CS;
  AMD_VMCB_SAVE_STATE_SELECTOR SS;
  AMD_VMCB_SAVE_STATE_SELECTOR DS;
  AMD_VMCB_SAVE_STATE_SELECTOR FS;
  AMD_VMCB_SAVE_STATE_SELECTOR GS;
  AMD_VMCB_SAVE_STATE_SELECTOR GDTR;
  AMD_VMCB_SAVE_STATE_SELECTOR LDTR;
  AMD_VMCB_SAVE_STATE_SELECTOR IDTR;
  AMD_VMCB_SAVE_STATE_SELECTOR TR;
  UINT8                        Reserved1[43];
  UINT8                        CPL;
  UINT32                       Reserved2;
  UINT64                       EFER;
  UINT8                        Reserved3[112];
  UINT64                       CR4;
  UINT64                       CR3;
  UINT64                       CR0;
  UINT64                       DR7;
  UINT64                       DR6;
  UINT64                       RFLAGS;
  UINT64                       RIP;
  UINT8                        Reserved4[88];
  UINT64                       RSP;
  UINT8                        Reserved5[24];
  UINT64                       RAX;
  UINT64                       STAR;
  UINT64                       LSTAR;
  UINT64                       CSTAR;
  UINT64                       SFMASK;
  UINT64                       KernelGsBase;
  UINT64                       SYSENTER_CS;
  UINT64                       SYSENTER_ESP;
  UINT64                       SYSENTER_EIP;
  UINT64                       CR2;
  UINT8                        Reserved6[32];
  UINT64                       G_PAT;
  UINT64                       DBGCTL;
  UINT64                       BR_FROM;
  UINT64                       BR_TO;
  UINT64                       LASTEXCPFROM;
  UINT64                       LASTEXCPTO;
} AMD_VMCB_SAVE_STATE_AREA_NON_ES;

STATIC_ASSERT (sizeof (AMD_VMCB_SAVE_STATE_AREA_NON_ES) == 0x298, "AMD_VMCB_SAVE_STATE_AREA_NON_ES is expected to be 0x298 bytes");

typedef PACKED struct {
  // rax shall be accessed via VMCB.
  UINT64 Rbx;
  UINT64 Rcx;
  UINT64 Rdx;
} AMD_INTEL_EMU_REGISTERS;

#pragma pack ()

#define GET_NEXT_THREAD_CONTEXT(Context)                               \
  (AMD_INTEL_EMU_THREAD_CONTEXT *)(                                    \
    (UINTN)((Context) + 1)                                             \
      + (mInternalMmioNumHandlers * sizeof (AMD_INTEL_EMU_MMIO_INFO))  \
    )

typedef struct AMD_INTEL_EMU_THREAD_CONTEXT AMD_INTEL_EMU_THREAD_CONTEXT;

typedef
VOID
(*AMD_INTEL_EMU_SINGLE_STEP_RESUME) (
  IN OUT AMD_VMCB_CONTROL_AREA  *Vmcb,
  IN     UINTN                  ResumeContext
  );

typedef
UINT64
(*AMD_INTEL_EMU_GET_MMIO_PAGE) (
  IN UINT64  BaseAddress,
  IN UINT64  FaultAddress
  );

typedef struct {
  UINT64                      Address;
  AMD_INTEL_EMU_GET_MMIO_PAGE GetPage;
} AMD_INTEL_EMU_MMIO_HANDLER_MAP;

typedef struct {
  UINT64                      Address;
  AMD_INTEL_EMU_GET_MMIO_PAGE GetPage;
  PAGE_TABLE_4K_ENTRY         *Pte;
} AMD_INTEL_EMU_MMIO_INFO;

struct AMD_INTEL_EMU_THREAD_CONTEXT {
  AMD_VMCB_CONTROL_AREA            *Vmcb;
  //
  // Single-stepping
  //
  BOOLEAN                          SsTf;
  BOOLEAN                          Btf;
  UINTN                            SingleStepContext;
  AMD_INTEL_EMU_SINGLE_STEP_RESUME SingleStepResume;
  //
  // iret interception
  //
  BOOLEAN                          IretTf;
  AMD_VMCB_EVENT                   QueueEvent;
  //
  // MMIO info
  //
  AMD_INTEL_EMU_MMIO_INFO          MmioInfo[];
};

typedef
VOID
(*AMD_INTEL_EMU_MSR_INTERCEPT) (
  IN OUT AMD_VMCB_SAVE_STATE_AREA_NON_ES  *SaveState,
  IN OUT AMD_INTEL_EMU_REGISTERS          *Registers,
  OUT    AMD_VMCB_CLEAN_FIELD             *CleanField
  );

typedef struct {
  UINT32                      MsrIndex;
  AMD_INTEL_EMU_MSR_INTERCEPT Read;
  AMD_INTEL_EMU_MSR_INTERCEPT Write;
} AMD_INTEL_EMU_MSR_INTERCEPT_INFO;

typedef
VOID
(EFIAPI *AMD_INTEL_EMU_ENABLE_VM) (
  IN OUT  AMD_VMCB_CONTROL_AREA  *Vmcb,
  IN     VOID                    *HostStack
  );

typedef struct {
  UINTN                         NumThreads;
  AMD_INTEL_EMU_THREAD_CONTEXT  *ThreadContexts;
  BOOLEAN                       NripSupport;
  BOOLEAN                       NpEnabled;
  VOID                          *LapicPage;
} AMD_INTEL_EMU_RUNTIME_CONTEXT;

typedef
VOID
(EFIAPI *AMD_INTEL_EMU_RUNTIME_ENTRY) (
  IN  CONST AMD_INTEL_EMU_RUNTIME_CONTEXT     *Context,
  OUT AMD_INTEL_EMU_ENABLE_VM                 *EnableVm,
  OUT UINTN                                   *NumMsrIntercepts,
  OUT CONST AMD_INTEL_EMU_MSR_INTERCEPT_INFO  **MsrIntercepts
  );

UINT64
AmdIntelEmuInternalMmioLapic (
  IN UINT64  BaseAddress,
  IN UINT64  FaultAddress
  );

/**
  Read from a local APIC register.

  This function reads from a local APIC register either in xAPIC or x2APIC mode.
  It is required that in xAPIC mode wider registers (64-bit or 256-bit) must be
  accessed using multiple 32-bit loads or stores, so this function only performs
  32-bit read.

  @param  MmioOffset  The MMIO offset of the local APIC register in xAPIC mode.
                      It must be 16-byte aligned.

  @return 32-bit      Value read from the register.

**/
UINT32
AmdIntelEmuReadLocalApicReg (
  IN UINTN  MmioOffset
  );

/**
  Retrieve the base address of local APIC.

  @return The base address of local APIC.

**/
UINTN
AmdIntelEmuGetLocalApicBaseAddress (
  VOID
  );

/**
  Initialize the local APIC timer.

  The local APIC timer is initialized and enabled.

  @param DivideValue   The divide value for the DCR. It is one of 1,2,4,8,16,32,64,128.
                       If it is 0, then use the current divide value in the DCR.
  @param InitCount     The initial count value.
  @param PeriodicMode  If TRUE, timer mode is peridoic. Othewise, timer mode is one-shot.
  @param Vector        The timer interrupt vector number.

**/
VOID
AmdIntelEmuInitializeApicTimer (
  IN UINTN   DivideValue,
  IN UINT32  InitCount,
  IN BOOLEAN PeriodicMode,
  IN UINT8   Vector
  );

/**
  Disable the local APIC timer interrupt.

**/
VOID
AmdIntelEmuDisableApicTimerInterrupt (
  VOID
  );

extern CONST UINTN                    mInternalMmioNumHandlers;
extern AMD_INTEL_EMU_MMIO_HANDLER_MAP mInternalMmioHandlerMap[];

#endif // AMD_INTEL_EMU_H_
