#include <stdio.h>

typedef enum{
    DU_SID_plmnIdInfo               = 0x0000000000000001UL,  
    DU_SID_gnbDuInfo                = 0x0000000000000002UL,
	DU_SID_duIpInfoList             = 0x0000000000000004UL,
	DU_SID_rlcBearerCfg             = 0x0000000000000008UL,

    DU_SID_CommonALL                = 0x000000000000000fUL,
	
    DU_SID_cellIdentityInfo         = 0x0000000000000010UL,
    DU_SID_cellSelecInfo            = 0x0000000000000020UL,
    DU_SID_connEstFailCtl           = 0x0000000000000040UL,
    DU_SID_siSchePr                 = 0x0000000000000080UL,
    DU_SID_siScheInfo               = 0x0000000000000100UL,
    DU_SID_sibCfgInfo               = 0x0000000000000200UL,
    DU_SID_siReqCfg                 = 0x0000000000000400UL,
    DU_SID_uacBarringPr             = 0x0000000000000800UL,
    DU_SID_uacBarringPerCatList     = 0x0000000000001000UL,
    DU_SID_uacBarringPerPlmnList    = 0x0000000000002000UL,
    DU_SID_uacBarringInfoSetList    = 0x0000000000004000UL,
    DU_SID_uacAct1SelectAssistInfo  = 0x0000000000008000UL,
    DU_SID_ueTimesAndConstants      = 0x0000000000010000UL,
    DU_SID_servCellCfgCommon        = 0x0000000000020000UL,
    DU_SID_tddCfg                   = 0x0000000000040000UL,
    DU_SID_tddUlDlPatternCfg        = 0x0000000000080000UL,
    DU_SID_nrMultiBandList          = 0x0000000000100000UL,
    DU_SID_scsSpecificCarrierList   = 0x0000000000200000UL,
    DU_SID_initBwpinfo              = 0x0000000000400000UL,
    DU_SID_freqInfoDl               = 0x0000000000800000UL,
    DU_SID_pdcchCfgCommon           = 0x0000000001000000UL,
    DU_SID_pdschCfgCommon           = 0x0000000002000000UL,
    DU_SID_bcchCfg                  = 0x0000000004000000UL,
    DU_SID_pcchCfg                  = 0x0000000008000000UL,
    DU_SID_freqInfoUl               = 0x0000000010000000UL,
    DU_SID_rachCfgCommon            = 0x0000000020000000UL,
    DU_SID_puschCfgCommon           = 0x0000000040000000UL,
    DU_SID_pucchCfgCommon           = 0x0000000080000000UL,

    DU_SID_SIB_ALL                  = 0x00000000fffffff0UL,
    
    DU_SID_timeAlignmentTimerCommon = 0x0000000100000000UL,
    DU_SID_cellMode                 = 0x0000000200000000UL,
    DU_SID_macCellGroupCfg          = 0x0000000400000000UL,
    DU_SID_phyCellGroupCfg          = 0x0000000800000000UL,
    DU_SID_duSpcellCfg              = 0x0000001000000000UL,
    DU_SID_pdschServCellCfg         = 0x0000002000000000UL,
    DU_SID_initDlBwpPr              = 0x0000004000000000UL,
    DU_SID_initDlBwpPdcchCfg        = 0x0000008000000000UL,
    DU_SID_uplinkCfg                = 0x0000010000000000UL,
    DU_SID_puschCfg                 = 0x0000020000000000UL,

    DU_SID_CellALL                  = 0x000003fffffffff0UL,
    
    DU_SID_all                      = 0xffffffffffffffffUL,
}OM_DU_para_struct_id;
typedef enum {
	m1 = 0x0000000000001,
	mmax=0xffffffffffffffff,
}lmask_t;


int main()
{
	lmask_t lm = mmax;
	OM_DU_para_struct_id sid = DU_SID_uacBarringPerPlmnList|DU_SID_initDlBwpPdcchCfg|DU_SID_gnbDuInfo;
	printf("%lx, %lx\n", lm, sid);
}
