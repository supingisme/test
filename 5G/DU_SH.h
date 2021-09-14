/**
 *  中国移动5G一体化皮基站扩展型一体化皮基站网管南向接口数据模型规范v1.1.0.xlsx
 *  SH
 */
#ifndef __DU_SH_H
#define __DU_SH_H 1


/* 物理层配置参数 */
struct PhyParamsMgmt {
    UINT32 OffsetToPointA; // SSB的PRB0中子载波0位置与PointA之间偏移值
    UINT32 FreqBandIndicatorNR;        // NR频段指示
    UINT32 DLOffsetToCarrier;            // 载波偏置(下行)
    UINT32 DLSubcarrierSpacing;        // 子载波间隔(下行)
    UINT32 DLCarrierBandwidth;        // 带宽值(下行)
    UINT32 AbsoluteFrequencyPointA;    // PointA绝对频点号
    UINT32 ULOffsetToCarrier;            // 载波偏置(上行)
    UINT32 ULSubcarrierSpacing;        // 子载波间隔(上行)
    UINT32 ULCarrierBandwidth;        // 带宽值(上行)
    CHAR   InOneGroup[8];                // SSB索引bit位
    UINT32 SsbPeriodicityServingCell;// SSB周期
    INT32  SsPBCHBlockPower;        // SSB Block功率值
    UINT32 SsbSubcarrierOffset;        // SSB子载波偏置
    CHAR   SubCarrierSpacingCommon[64];    // 公共子载波间隔
    UINT32 ReferenceSubcarrierSpacing;// 参考子载波间隔
    UINT32 M1DlULTransmissionPeriodicity; // 模式1的传输周期
    UINT32 M1NrofDownlinkSlots;        // 模式1的连续下行时隙数
    UINT32 M1NrofDownlinkSymbols;     // 模式1的连续下行符号数
    UINT32 M1NrofUplinkSlots;            // 模式1的连续上行时隙数
    UINT32 M1NrofUplinkSymbols;        // 模式1的连续上行符号数
    UINT32 M2DlULTransmissionPeriodicity; // 模式2的传输周期
    UINT32 M2NrofDownlinkSlots;        // 模式2的连续下行时隙数
    UINT32 M2NrofDownlinkSymbols;     // 模式2的连续下行符号数
    UINT32 M2NrofUplinkSlots;            // 模式2的连续上行时隙数
    UINT32 M2NrofUplinkSymbols;        // 模式2的连续上行符号数
    UINT32 DLStartPrbPosition;        // 起始PRB位置（下行）
    UINT32 DLBandwidth;                // BWP带宽（下行）{5,10,15,20,25,30,40,50,60,80,90,100}MHz
    UINT32 BWPDLSubcarrierSpacing;        // BWP子载波间隔（下行）
    CHAR   DLCyclicPrefix[64];            // 循环前缀（下行）
    UINT32 ULStartPrbPosition;        // 起始PRB位置（上行）
    UINT32 ULBandwidth;                // BWP带宽（上行）
    UINT32 BWPULSubcarrierSpacing;        // BWP子载波间隔（上行）
    CHAR   ULCyclicPrefix[64];            // 循环前缀（上行）
    CHAR   TimeAlignmentTimerCommon[64];// 上行提前量
    UINT32 PrachConfigurationIndex;    // PRACH时域配置
    CHAR   Msg1FDM[64];                 // PRACH频域资源个数
    UINT32 Msg1FrequencyStart;        // PRACH频域起始位置
    UINT32 ZeroCorrelationZoneConfig;// Ncs值
    UINT32 GroupHoppingEnabledTransformPrecoding;// 序列组跳频开关
    UINT32 K2;                        // PDCCH到PUSCH调度延迟
    UINT32 PUSCHMappingType;                // PUSCH映射类型
    UINT32 PUSCHStartSymbolAndLength;    // PUSCH起始符号和长度
    INT32  Msg3DeltaPreamble;         // MSG3与preamble之间发送功率的偏移值
    INT32  P0NominalWithGrant;        // PUSCH功率值P0
    UINT32 PucchResourceCommon;        // PUCCH公共资源
    UINT32 PucchGroupHopping;        // PUCCH组跳频开关
    UINT32 HoppingId;                // PUCCH加扰ID
    INT32  P0nominal;                // PUCCH功率值P0
    UINT32 RootType;                // 根序列类型
    UINT32 RootSequenceIndex;        // 根序列索引
    UINT32 Msg1SubcarrierSpacing;    // msg1子载波间隔
    UINT32 RestrictedSetConfig;        // 限制集配置参数
    UINT32 DmrsTypeAPosition;        // DMRS TypeA位置
    UINT32 ControlResourceSetZero;    // CORESET#0
    UINT32 SearchSpaceZero;            // 搜索空间#0
    UINT32 SearchSpaceSIB1;            // SIB1搜索空间
    UINT32 SearchSpaceOtherSystemInformation;// 其它SI搜索空间
    UINT32 PagingSearchSpace;        // 寻呼搜索空间
    UINT32 RaSearchSpace;            // 随机接入搜索空间
    UINT32 ControlResourceSetId;    // 控制资源集ID
    CHAR   FrequencyDomainResources[45];// 控制资源集频域范围
    UINT32 Nsymbols;                // 符号数
    UINT32 CceRegMappingType;        // CCE-REG映射类型
    UINT32 RegBundleSize;            // REG绑定大小
    UINT32 InterleaverSize;            // 交织长度
    UINT32 ShiftIndex;                // 转换索引
    UINT32 PrecoderGranularity;        // 预编码粒度
    UINT32 PdcchDMRSScramblingID;    // PDCCH DMRS加扰ID
    UINT32 SearchSpaceId;            // 搜索空间ID
    //UINT32 ControlResourceSetId;    // 控制资源集ID
    UINT32 MonitoringSlotPeriodicity;// 搜索空间周期[1,2,4,5,l5,10,16,20,40,80,160,320,640,1280,2560,0x00000FFF]
    UINT32 MonitoringSlotOffset;    // 监测周期偏置
    UINT32 MonitorTimeSlots;                // 监测时隙数目
    CHAR   MonitoringSymbolsWithinSlot[14];// 监测符号位置
    UINT32 AggregationLevel1;        // 聚合等级1
    UINT32 AggregationLevel2;        // 聚合等级2
    UINT32 AggregationLevel4;        // 聚合等级4
    UINT32 AggregationLevel8;        // 聚合等级8
    UINT32 AggregationLevel16;        // 聚合等级16
    UINT32 SearchSpaceType;            // 搜索空间类型
    UINT32 DciFormat00And10En;        // 公共搜索空间DCI格式开关
    UINT32 UeSpecificDciFormats;    // UE专用DCI格式
    UINT32 K0;                        // PDCCH到PDSCH调度延迟
    UINT32 PDSCHMappingType;                // PDSCH映射类型
    UINT32 PDSCHStartSymbolAndLength;    // PDSCH起始符号和长度
};


/* MAC层配置参数 */
struct MacParamsMgmt {
    UINT32 TotalNumberOfRAPreambles;// Preamble码个数
    UINT32 SSBPerRACHOccasionChoice;//PRACH对应SSB个数
    UINT32 CBPreamblesPerSSB;//SSB对应前导码个数
    UINT32 RaMsg3SizeGroupA;// Msg3 GroupA大小门限
    UINT32 MessagePowerOffsetGroupB;// Preamble码选择门限值
    UINT32 NumberOfRAPreamblesGroupA;// GroupA中Preamble码个数
    UINT32 RaContentionResolutionTimer;// 随机接入竞争窗长
    UINT32 RsrpThresholdSSB;// 随机接入SSB RSRP门限
    INT32  PreambleReceivedTargetPower;//前导目标接收功率
    UINT32 PreambleTransMax;//最大前导发送次数
    UINT32 PowerRampingStep;//前导爬坡步长
    UINT32 RaResponseWindowRAR;//窗长
    UINT32 Msg3TransformPrecoder;// PrecoderMsg3预编码
};



#endif /*<__DU_SH_H>*/

