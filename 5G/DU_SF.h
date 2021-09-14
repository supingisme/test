/**
 *  中国移动5G一体化皮基站扩展型一体化皮基站网管南向接口数据模型规范v1.1.0.xlsx
 *  SF
 *  整理：Rong Tao
 */
#ifndef __DU_SF_H
#define __DU_SF_H 1

#include <stdbool.h>

/* 小区闭塞 */
struct CellBarred {
    BOOL CellBarred; //{barred, notBarred}
};


/* 小区参数管理 */
struct CellParasMgmt {
    CHAR    NRARFCNDL[128];     //下行earfcn
    CHAR    PhyCellID[512];     //PCI
    CHAR    DLbandwidth[32];    //下行带宽
    CHAR    ULbandwidth[32];    //上行带宽
    CHAR    PSCHPowerOffset[512];//主同步信道相对SS/PBCH block 的功率偏置,取值范围{db0, db3}
    CHAR    NRARFCNUL[128];     //上行或双向E-UTRA载频：NRARFCNUL
    UINT32  FreqBandIndicator;  //频带指示
    UINT32  MaxTxPower;         //最大发射功率
    UINT32  SsPBCHBlockPower;   //SSB Block功率值:readonly[-60:50]
};


/* 基站运行状态参数 */
struct BSRunningStatus {
#if 0
    bool radioSwitch;//"一体化皮基基站或扩展型一体化皮基站主机射频开关：
                        //true：标识射频开启；false：标识射频关闭。
    bool FAPStatus;//"FAP当前操作状态：
                    //false：禁止;true:启动
    bool RFStatus;  //RF发射机的当前状态：
                    //true：RF发射机运行状态；false：RF发射机是停止状态。"
#endif
    bool AdminState;//基站管理状态: 0:关闭,1:开启
    bool OpState;//基站运行状态: 0:禁止,1:启动
    bool RFTxStatus;//	基站射频状态: 0:关闭,1:开启
};



/* 小区标识参数 Cell identification parameter */
struct CellIdentificationParams {
    UINT32      gNBId;//gNB标识[0:‭4294967295‬]
    CHAR        gNBName[150];//gNB名称
    enum CellType{ SUB1G,SUB6G,ABOVE6G }
                cellType;//自定义
    BOOL        cellReservedForOtherUse;//供运营商使用的小区预留标志,小区预留标识总开关
    UINT32      TAC;//跟踪区代码[0:16777215]
    INT         ranac;//RAN区域编码INTEGER (0..255)
    UINT32      NrcellIdentity;//小区cellIdentity	unsignedInt[0:‭68719476735‬]‬‬
    enum PLMNFlag{reserved, notReserved}
                CellReservedForOperatorUse;
    CHAR        PLMNID[6];//由MCC和MNC组成
    UINT32      SNSSAI;//unsignedInt[0:‭4294967295‬]‬‬	由SST和SD组成
};

/* 小区服务参数 */
struct CellServerParams {
    struct CellBarred               cell_barred;
    struct CellParasMgmt            cell_params_mgmt;
    struct BSRunningStatus          cell_run_status;
    struct CellIdentificationParams cell_iden_params;
};

#endif /*<__DU_SF_H>*/
