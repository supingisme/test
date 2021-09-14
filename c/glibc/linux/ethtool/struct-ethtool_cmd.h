
/**
 * struct ethtool_cmd - DEPRECATED, link control and status
 * This structure is DEPRECATED, please use struct ethtool_link_settings.
 * @cmd: Command number = %ETHTOOL_GSET or %ETHTOOL_SSET
 * @supported: Bitmask of %SUPPORTED_* flags for the link modes,
 *	physical connectors and other link features for which the
 *	interface supports autonegotiation or auto-detection.
 *	Read-only.
 * @advertising: Bitmask of %ADVERTISED_* flags for the link modes,
 *	physical connectors and other link features that are
 *	advertised through autonegotiation or enabled for
 *	auto-detection.
 * @speed: Low bits of the speed, 1Mb units, 0 to INT_MAX or SPEED_UNKNOWN
 * @duplex: Duplex mode; one of %DUPLEX_*
 * @port: Physical connector type; one of %PORT_*
 * @phy_address: MDIO address of PHY (transceiver); 0 or 255 if not
 *	applicable.  For clause 45 PHYs this is the PRTAD.
 * @transceiver: Historically used to distinguish different possible
 *	PHY types, but not in a consistent way.  Deprecated.
 * @autoneg: Enable/disable autonegotiation and auto-detection;
 *	either %AUTONEG_DISABLE or %AUTONEG_ENABLE
 * @mdio_support: Bitmask of %ETH_MDIO_SUPPORTS_* flags for the MDIO
 *	protocols supported by the interface; 0 if unknown.
 *	Read-only.
 * @maxtxpkt: Historically used to report TX IRQ coalescing; now
 *	obsoleted by &struct ethtool_coalesce.  Read-only; deprecated.
 * @maxrxpkt: Historically used to report RX IRQ coalescing; now
 *	obsoleted by &struct ethtool_coalesce.  Read-only; deprecated.
 * @speed_hi: High bits of the speed, 1Mb units, 0 to INT_MAX or SPEED_UNKNOWN
 * @eth_tp_mdix: Ethernet twisted-pair MDI(-X) status; one of
 *	%ETH_TP_MDI_*.  If the status is unknown or not applicable, the
 *	value will be %ETH_TP_MDI_INVALID.  Read-only.
 * @eth_tp_mdix_ctrl: Ethernet twisted pair MDI(-X) control; one of
 *	%ETH_TP_MDI_*.  If MDI(-X) control is not implemented, reads
 *	yield %ETH_TP_MDI_INVALID and writes may be ignored or rejected.
 *	When written successfully, the link should be renegotiated if
 *	necessary.
 * @lp_advertising: Bitmask of %ADVERTISED_* flags for the link modes
 *	and other link features that the link partner advertised
 *	through autonegotiation; 0 if unknown or not applicable.
 *	Read-only.
 *
 * The link speed in Mbps is split between @speed and @speed_hi.  Use
 * the ethtool_cmd_speed() and ethtool_cmd_speed_set() functions to
 * access it.
 *
 * If autonegotiation is disabled, the speed and @duplex represent the
 * fixed link mode and are writable if the driver supports multiple
 * link modes.  If it is enabled then they are read-only; if the link
 * is up they represent the negotiated link mode; if the link is down,
 * the speed is 0, %SPEED_UNKNOWN or the highest enabled speed and
 * @duplex is %DUPLEX_UNKNOWN or the best enabled duplex mode.
 *
 * Some hardware interfaces may have multiple PHYs and/or physical
 * connectors fitted or do not allow the driver to detect which are
 * fitted.  For these interfaces @port and/or @phy_address may be
 * writable, possibly dependent on @autoneg being %AUTONEG_DISABLE.
 * Otherwise, attempts to write different values may be ignored or
 * rejected.
 *
 * Users should assume that all fields not marked read-only are
 * writable and subject to validation by the driver.  They should use
 * %ETHTOOL_GSET to get the current values before making specific
 * changes and then applying them with %ETHTOOL_SSET.
 *
 * Drivers that implement set_settings() should validate all fields
 * other than @cmd that are not described as read-only or deprecated,
 * and must ignore all fields described as read-only.
 *
 * Deprecated fields should be ignored by both users and drivers.
 */
struct ethtool_cmd {
	__u32	cmd;
	__u32	supported;
	__u32	advertising;
	__u16	speed;
	__u8	duplex;
	__u8	port;
	__u8	phy_address;
	__u8	transceiver;
	__u8	autoneg;
	__u8	mdio_support;
	__u32	maxtxpkt;
	__u32	maxrxpkt;
	__u16	speed_hi;
	__u8	eth_tp_mdix;
	__u8	eth_tp_mdix_ctrl;
	__u32	lp_advertising;
	__u32	reserved[2];
};

