NDPI_SRC := ../../src
NDPI_PRO := ${NDPI_SRC}/lib/protocols
LPI_SRC := ../lpi/src
LPI_PRO_T := ${LPI_SRC}/tcp
LPI_PRO_U := ${LPI_SRC}/udp

ccflags-y += -I${src}/${NDPI_SRC}/include -I${src}/${NDPI_SRC}/lib -I${src}/${LPI_SRC} -I${src}/../libre -I${src}/${NDPI_SRC}/lib/third_party/include
ccflags-y += -DHAVE_CONFIG_H -DNDPI_LIB_COMPILATION -DOPENDPI_NETFILTER_MODULE  -g


MODULES_DIR := /lib/modules/$(shell uname -r)
KERNEL_DIR := ${MODULES_DIR}/build

obj-m := xt_ndpi.o
xt_ndpi-y := main.o \
        ${LPI_SRC}/libprotoident.o \
        ${LPI_SRC}/proto_manager.o \
        ${LPI_SRC}/proto_common.o \
        ${LPI_PRO_T}/lpi_360safeguard.o \
        ${LPI_PRO_T}/lpi_4d.o \
        ${LPI_PRO_T}/lpi_acestream.o \
        ${LPI_PRO_T}/lpi_afp.o \
        ${LPI_PRO_T}/lpi_airdroid.o \
        ${LPI_PRO_T}/lpi_airmedia.o \
        ${LPI_PRO_T}/lpi_akamai.o \
        ${LPI_PRO_T}/lpi_amp.o \
        ${LPI_PRO_T}/lpi_antcoin.o \
        ${LPI_PRO_T}/lpi_appearin.o \
        ${LPI_PRO_T}/lpi_apple_push.o \
        ${LPI_PRO_T}/lpi_ares.o \
        ${LPI_PRO_T}/lpi_badbaidu.o \
        ${LPI_PRO_T}/lpi_baofeng_tcp.o \
        ${LPI_PRO_T}/lpi_bitcoin.o \
        ${LPI_PRO_T}/lpi_bitextend.o \
        ${LPI_PRO_T}/lpi_bittorrent.o \
        ${LPI_PRO_T}/lpi_blackdesert.o \
        ${LPI_PRO_T}/lpi_blizzard.o \
        ${LPI_PRO_T}/lpi_btsync.o \
        ${LPI_PRO_T}/lpi_cacaoweb.o \
        ${LPI_PRO_T}/lpi_cgp.o \
        ${LPI_PRO_T}/lpi_chatango.o \
        ${LPI_PRO_T}/lpi_cisco_vpn.o \
        ${LPI_PRO_T}/lpi_clashofclans.o \
        ${LPI_PRO_T}/lpi_clubbox.o \
        ${LPI_PRO_T}/lpi_cod_waw.o \
        ${LPI_PRO_T}/lpi_conquer.o \
        ${LPI_PRO_T}/lpi_crashplan.o \
        ${LPI_PRO_T}/lpi_crossfire_tcp.o \
        ${LPI_PRO_T}/lpi_cryptic.o \
        ${LPI_PRO_T}/lpi_cvs.o \
        ${LPI_PRO_T}/lpi_dash.o \
        ${LPI_PRO_T}/lpi_dell_backup.o \
        ${LPI_PRO_T}/lpi_destiny.o \
        ${LPI_PRO_T}/lpi_diablo3.o \
        ${LPI_PRO_T}/lpi_dianping_tcp.o \
        ${LPI_PRO_T}/lpi_directconnect.o \
        ${LPI_PRO_T}/lpi_dns.o \
        ${LPI_PRO_T}/lpi_dogecoin.o \
        ${LPI_PRO_T}/lpi_douyu.o \
        ${LPI_PRO_T}/lpi_douyu_chat.o \
        ${LPI_PRO_T}/lpi_duelingnetwork.o \
        ${LPI_PRO_T}/lpi_dvrns.o \
        ${LPI_PRO_T}/lpi_dxp.o \
        ${LPI_PRO_T}/lpi_ea_games.o \
        ${LPI_PRO_T}/lpi_emule.o \
        ${LPI_PRO_T}/lpi_eye.o \
        ${LPI_PRO_T}/lpi_facebook_turn.o \
        ${LPI_PRO_T}/lpi_fb_message.o \
        ${LPI_PRO_T}/lpi_fbcdn_ssl.o \
        ${LPI_PRO_T}/lpi_ffxiv.o \
        ${LPI_PRO_T}/lpi_flash.o \
        ${LPI_PRO_T}/lpi_fliggy.o \
        ${LPI_PRO_T}/lpi_fring.o \
        ${LPI_PRO_T}/lpi_ftpcontrol.o \
        ${LPI_PRO_T}/lpi_ftpdata.o \
        ${LPI_PRO_T}/lpi_fuckcoin.o \
        ${LPI_PRO_T}/lpi_funshion.o \
        ${LPI_PRO_T}/lpi_gamespy.o \
        ${LPI_PRO_T}/lpi_giop.o \
        ${LPI_PRO_T}/lpi_git.o \
        ${LPI_PRO_T}/lpi_glupteba.o \
        ${LPI_PRO_T}/lpi_gnutella.o \
        ${LPI_PRO_T}/lpi_goku.o \
        ${LPI_PRO_T}/lpi_googlehangouts.o \
        ${LPI_PRO_T}/lpi_graalonlineera.o \
        ${LPI_PRO_T}/lpi_guildwars2.o \
        ${LPI_PRO_T}/lpi_hamachi.o \
        ${LPI_PRO_T}/lpi_harveys.o \
        ${LPI_PRO_T}/lpi_hearthstone.o \
        ${LPI_PRO_T}/lpi_hola.o \
        ${LPI_PRO_T}/lpi_http_badport.o \
        ${LPI_PRO_T}/lpi_http.o \
        ${LPI_PRO_T}/lpi_http_nonstandard.o \
        ${LPI_PRO_T}/lpi_https.o \
        ${LPI_PRO_T}/lpi_http_tunnel.o \
        ${LPI_PRO_T}/lpi_ica.o \
        ${LPI_PRO_T}/lpi_id.o \
        ${LPI_PRO_T}/lpi_idrivesync.o \
        ${LPI_PRO_T}/lpi_imap.o \
        ${LPI_PRO_T}/lpi_imaps.o \
        ${LPI_PRO_T}/lpi_imesh.o \
        ${LPI_PRO_T}/lpi_invalid.o \
        ${LPI_PRO_T}/lpi_invalid_bittorrent.o \
        ${LPI_PRO_T}/lpi_invalid_http.o \
        ${LPI_PRO_T}/lpi_invalid_pop.o \
        ${LPI_PRO_T}/lpi_invalid_smtp.o \
        ${LPI_PRO_T}/lpi_ipop.o \
        ${LPI_PRO_T}/lpi_ipsharkk.o \
        ${LPI_PRO_T}/lpi_irc.o \
        ${LPI_PRO_T}/lpi_java.o \
        ${LPI_PRO_T}/lpi_jedi.o \
        ${LPI_PRO_T}/lpi_jx3online.o \
        ${LPI_PRO_T}/lpi_kakao.o \
        ${LPI_PRO_T}/lpi_kankan_tcp.o \
        ${LPI_PRO_T}/lpi_kaseya.o \
        ${LPI_PRO_T}/lpi_kaspersky.o \
        ${LPI_PRO_T}/lpi_kik.o \
        ${LPI_PRO_T}/lpi_kuaibo.o \
        ${LPI_PRO_T}/lpi_ldap.o \
        ${LPI_PRO_T}/lpi_lifeforge.o \
        ${LPI_PRO_T}/lpi_line.o \
        ${LPI_PRO_T}/lpi_litecoin.o \
        ${LPI_PRO_T}/lpi_llp2p.o \
        ${LPI_PRO_T}/lpi_maplestory_china.o \
        ${LPI_PRO_T}/lpi_maxicloud.o \
        ${LPI_PRO_T}/lpi_message4u.o \
        ${LPI_PRO_T}/lpi_minecraft.o \
        ${LPI_PRO_T}/lpi_mitglieder.o \
        ${LPI_PRO_T}/lpi_mms.o \
        ${LPI_PRO_T}/lpi_mongo.o \
        ${LPI_PRO_T}/lpi_mp2p.o \
        ${LPI_PRO_T}/lpi_msn.o \
        ${LPI_PRO_T}/lpi_msnc.o \
        ${LPI_PRO_T}/lpi_msnv.o \
        ${LPI_PRO_T}/lpi_munin.o \
        ${LPI_PRO_T}/lpi_mysql.o \
        ${LPI_PRO_T}/lpi_mystery_100_star.o \
        ${LPI_PRO_T}/lpi_mystery_8000.o \
        ${LPI_PRO_T}/lpi_mystery_9000.o \
        ${LPI_PRO_T}/lpi_mystery_conn.o \
        ${LPI_PRO_T}/lpi_mystery_iG.o \
        ${LPI_PRO_T}/lpi_mystery_pspr.o \
        ${LPI_PRO_T}/lpi_mystery_rxxf.o \
        ${LPI_PRO_T}/lpi_mystery_symantec.o \
        ${LPI_PRO_T}/lpi_mzinga.o \
        ${LPI_PRO_T}/lpi_ncsoft.o \
        ${LPI_PRO_T}/lpi_ndt_tput.o \
        ${LPI_PRO_T}/lpi_netbios.o \
        ${LPI_PRO_T}/lpi_netcat_cctv.o \
        ${LPI_PRO_T}/lpi_netmfp.o \
        ${LPI_PRO_T}/lpi_nntp.o \
        ${LPI_PRO_T}/lpi_nntps.o \
        ${LPI_PRO_T}/lpi_nopayload.o \
        ${LPI_PRO_T}/lpi_nofirstpkt.o \
        ${LPI_PRO_T}/lpi_norton_backup.o \
        ${LPI_PRO_T}/lpi_notes_rpc.o \
        ${LPI_PRO_T}/lpi_omegle.o \
        ${LPI_PRO_T}/lpi_openvpn.o \
        ${LPI_PRO_T}/lpi_ourworld.o \
        ${LPI_PRO_T}/lpi_palringo.o \
        ${LPI_PRO_T}/lpi_paltalk.o \
        ${LPI_PRO_T}/lpi_pandatv.o \
        ${LPI_PRO_T}/lpi_pando.o \
        ${LPI_PRO_T}/lpi_pdbox.o \
        ${LPI_PRO_T}/lpi_pop3.o \
        ${LPI_PRO_T}/lpi_pop3s.o \
        ${LPI_PRO_T}/lpi_postgresql.o \
        ${LPI_PRO_T}/lpi_pptp.o \
        ${LPI_PRO_T}/lpi_psn_store.o \
        ${LPI_PRO_T}/lpi_qcloud_ilvb.o \
        ${LPI_PRO_T}/lpi_qq_tcp.o \
        ${LPI_PRO_T}/lpi_qqdownload.o \
        ${LPI_PRO_T}/lpi_qqlive_tcp.o \
        ${LPI_PRO_T}/lpi_qvod.o \
        ${LPI_PRO_T}/lpi_razor.o \
        ${LPI_PRO_T}/lpi_rbls.o \
        ${LPI_PRO_T}/lpi_rdp.o \
        ${LPI_PRO_T}/lpi_realvnc.o \
        ${LPI_PRO_T}/lpi_rejection.o \
        ${LPI_PRO_T}/lpi_relay.o \
        ${LPI_PRO_T}/lpi_revolver_nblbt.o \
        ${LPI_PRO_T}/lpi_rfb.o \
        ${LPI_PRO_T}/lpi_rpcscan.o \
        ${LPI_PRO_T}/lpi_rsync.o \
        ${LPI_PRO_T}/lpi_rtmp.o \
        ${LPI_PRO_T}/lpi_rtsp.o \
        ${LPI_PRO_T}/lpi_runescape.o \
        ${LPI_PRO_T}/lpi_s7comm.o \
        ${LPI_PRO_T}/lpi_saprouter.o \
        ${LPI_PRO_T}/lpi_second_life.o \
        ${LPI_PRO_T}/lpi_shoutcast.o \
        ${LPI_PRO_T}/lpi_silkroadonline.o \
        ${LPI_PRO_T}/lpi_sip.o \
        ${LPI_PRO_T}/lpi_skype_tcp.o \
        ${LPI_PRO_T}/lpi_smb.o \
        ${LPI_PRO_T}/lpi_smite_tcp.o \
        ${LPI_PRO_T}/lpi_smtp.o \
        ${LPI_PRO_T}/lpi_smtps.o \
        ${LPI_PRO_T}/lpi_socks4.o \
        ${LPI_PRO_T}/lpi_socks5.o \
        ${LPI_PRO_T}/lpi_spdy.o \
        ${LPI_PRO_T}/lpi_speedin.o \
        ${LPI_PRO_T}/lpi_speedtest.o \
        ${LPI_PRO_T}/lpi_spotify.o \
        ${LPI_PRO_T}/lpi_ssh.o \
        ${LPI_PRO_T}/lpi_ssl.o \
        ${LPI_PRO_T}/lpi_steam.o \
        ${LPI_PRO_T}/lpi_stratum.o \
        ${LPI_PRO_T}/lpi_stun.o \
        ${LPI_PRO_T}/lpi_supl.o \
        ${LPI_PRO_T}/lpi_svn.o \
        ${LPI_PRO_T}/lpi_talesrunner.o \
        ${LPI_PRO_T}/lpi_tankix.o \
        ${LPI_PRO_T}/lpi_taobao.o \
        ${LPI_PRO_T}/lpi_tds.o \
        ${LPI_PRO_T}/lpi_teamviewer.o \
        ${LPI_PRO_T}/lpi_telecomkey.o \
        ${LPI_PRO_T}/lpi_telegram.o \
        ${LPI_PRO_T}/lpi_telnet.o \
        ${LPI_PRO_T}/lpi_telnet_exploit.o \
        ${LPI_PRO_T}/lpi_tencent_games.o \
        ${LPI_PRO_T}/lpi_tenfivecoin.o \
        ${LPI_PRO_T}/lpi_tensafe.o \
        ${LPI_PRO_T}/lpi_tera.o \
        ${LPI_PRO_T}/lpi_tetrisonline.o \
        ${LPI_PRO_T}/lpi_thedivision.o \
        ${LPI_PRO_T}/lpi_tip.o \
        ${LPI_PRO_T}/lpi_tor.o \
        ${LPI_PRO_T}/lpi_tpkt.o \
        ${LPI_PRO_T}/lpi_trackmania.o \
        ${LPI_PRO_T}/lpi_trion.o \
        ${LPI_PRO_T}/lpi_trojan_win32_generic_sb.o \
        ${LPI_PRO_T}/lpi_trojan_zeroaccess.o \
        ${LPI_PRO_T}/lpi_twitcasting.o \
        ${LPI_PRO_T}/lpi_twitch_irc.o \
        ${LPI_PRO_T}/lpi_vainglory.o \
        ${LPI_PRO_T}/lpi_viber.o \
        ${LPI_PRO_T}/lpi_vmware.o \
        ${LPI_PRO_T}/lpi_vodlocker.o \
        ${LPI_PRO_T}/lpi_vpnrobot_tcp.o \
        ${LPI_PRO_T}/lpi_vpnunlimited_tcp.o \
        ${LPI_PRO_T}/lpi_warcraft3.o \
        ${LPI_PRO_T}/lpi_web_junk.o \
        ${LPI_PRO_T}/lpi_weblogic.o \
        ${LPI_PRO_T}/lpi_wechat.o \
        ${LPI_PRO_T}/lpi_weibo.o \
        ${LPI_PRO_T}/lpi_weiqi.o \
        ${LPI_PRO_T}/lpi_whatsapp.o \
        ${LPI_PRO_T}/lpi_whois.o \
        ${LPI_PRO_T}/lpi_winmx.o \
        ${LPI_PRO_T}/lpi_wizard101.o \
        ${LPI_PRO_T}/lpi_wns.o \
        ${LPI_PRO_T}/lpi_wow.o \
        ${LPI_PRO_T}/lpi_wuala.o \
        ${LPI_PRO_T}/lpi_xiami.o \
        ${LPI_PRO_T}/lpi_xmpp.o \
        ${LPI_PRO_T}/lpi_xmpps.o \
        ${LPI_PRO_T}/lpi_xunlei.o \
        ${LPI_PRO_T}/lpi_xunlei_accel.o \
        ${LPI_PRO_T}/lpi_xymon.o \
        ${LPI_PRO_T}/lpi_yahoo.o \
        ${LPI_PRO_T}/lpi_yahoo_error.o \
        ${LPI_PRO_T}/lpi_yahoo_games.o \
        ${LPI_PRO_T}/lpi_yahoo_webcam.o \
        ${LPI_PRO_T}/lpi_youku.o \
        ${LPI_PRO_T}/lpi_yy_tcp.o \
        ${LPI_PRO_T}/lpi_zabbix.o \
        ${LPI_PRO_T}/lpi_zero.o \
        ${LPI_PRO_T}/lpi_zoom_tcp.o \
        ${LPI_PRO_T}/lpi_zynga.o \
        ${LPI_PRO_U}/lpi_360cn.o \
        ${LPI_PRO_U}/lpi_360p2p.o \
        ${LPI_PRO_U}/lpi_aachen_udp.o \
        ${LPI_PRO_U}/lpi_acercloud.o \
        ${LPI_PRO_U}/lpi_akamai.o \
        ${LPI_PRO_U}/lpi_akamai_transfer.o \
        ${LPI_PRO_U}/lpi_amanda.o \
        ${LPI_PRO_U}/lpi_apple_facetime_init.o \
        ${LPI_PRO_U}/lpi_ares.o \
        ${LPI_PRO_U}/lpi_ark.o \
        ${LPI_PRO_U}/lpi_arma_server.o \
        ${LPI_PRO_U}/lpi_arma3_server.o \
        ${LPI_PRO_U}/lpi_avast_secure_dns.o \
        ${LPI_PRO_U}/lpi_backweb.o \
        ${LPI_PRO_U}/lpi_bacnet.o \
        ${LPI_PRO_U}/lpi_baiduyun_p2p.o \
        ${LPI_PRO_U}/lpi_baofeng_udp.o \
        ${LPI_PRO_U}/lpi_battlefield.o \
        ${LPI_PRO_U}/lpi_bjnp.o \
        ${LPI_PRO_U}/lpi_bmdp.o \
        ${LPI_PRO_U}/lpi_btsync.o \
        ${LPI_PRO_U}/lpi_canon_mfnp.o \
        ${LPI_PRO_U}/lpi_checkpoint_rdp.o \
        ${LPI_PRO_U}/lpi_chivalry.o \
        ${LPI_PRO_U}/lpi_cirn.o \
        ${LPI_PRO_U}/lpi_cisco_ipsec.o \
        ${LPI_PRO_U}/lpi_cisco_sslvpn.o \
        ${LPI_PRO_U}/lpi_cod.o \
        ${LPI_PRO_U}/lpi_combatarms.o \
        ${LPI_PRO_U}/lpi_combatarms_p2p.o \
        ${LPI_PRO_U}/lpi_crossfire.o \
        ${LPI_PRO_U}/lpi_crossout.o \
        ${LPI_PRO_U}/lpi_csgo.o \
        ${LPI_PRO_U}/lpi_csoriginal.o \
        ${LPI_PRO_U}/lpi_dahua.o \
        ${LPI_PRO_U}/lpi_db2.o \
        ${LPI_PRO_U}/lpi_dcc.o \
        ${LPI_PRO_U}/lpi_demonware.o \
        ${LPI_PRO_U}/lpi_destiny_udp.o \
        ${LPI_PRO_U}/lpi_dhcp.o \
        ${LPI_PRO_U}/lpi_dht_dict.o \
        ${LPI_PRO_U}/lpi_dht_other.o \
        ${LPI_PRO_U}/lpi_diablo2.o \
        ${LPI_PRO_U}/lpi_dianping_udp.o \
        ${LPI_PRO_U}/lpi_dianshijia.o \
        ${LPI_PRO_U}/lpi_directconnect.o \
        ${LPI_PRO_U}/lpi_discord.o \
        ${LPI_PRO_U}/lpi_dns.o \
        ${LPI_PRO_U}/lpi_dota2.o \
        ${LPI_PRO_U}/lpi_doyo.o \
        ${LPI_PRO_U}/lpi_driveshare.o \
        ${LPI_PRO_U}/lpi_dtls.o \
        ${LPI_PRO_U}/lpi_emule.o \
        ${LPI_PRO_U}/lpi_emule_weak.o \
        ${LPI_PRO_U}/lpi_epson.o \
        ${LPI_PRO_U}/lpi_eso.o \
        ${LPI_PRO_U}/lpi_esp_encap.o \
        ${LPI_PRO_U}/lpi_eye.o \
        ${LPI_PRO_U}/lpi_fasp.o \
        ${LPI_PRO_U}/lpi_forticlient_sslvpn.o \
        ${LPI_PRO_U}/lpi_fortinet.o \
        ${LPI_PRO_U}/lpi_foscam.o \
        ${LPI_PRO_U}/lpi_freechal.o \
        ${LPI_PRO_U}/lpi_funshion.o \
        ${LPI_PRO_U}/lpi_gamespy.o \
        ${LPI_PRO_U}/lpi_gangsofspace.o \
        ${LPI_PRO_U}/lpi_garena.o \
        ${LPI_PRO_U}/lpi_gearsofwar.o \
        ${LPI_PRO_U}/lpi_gnutella.o \
        ${LPI_PRO_U}/lpi_gnutella2.o \
        ${LPI_PRO_U}/lpi_gnutella_weak.o \
        ${LPI_PRO_U}/lpi_gotomeeting.o \
        ${LPI_PRO_U}/lpi_gprs_tunnel.o \
        ${LPI_PRO_U}/lpi_gsm.o \
        ${LPI_PRO_U}/lpi_h1z1.o \
        ${LPI_PRO_U}/lpi_halflife.o \
        ${LPI_PRO_U}/lpi_haloonline.o \
        ${LPI_PRO_U}/lpi_hamachi.o \
        ${LPI_PRO_U}/lpi_heroes_generals.o \
        ${LPI_PRO_U}/lpi_hots.o \
        ${LPI_PRO_U}/lpi_icp.o \
        ${LPI_PRO_U}/lpi_imesh.o \
        ${LPI_PRO_U}/lpi_ipmsg.o \
        ${LPI_PRO_U}/lpi_ipv6.o \
        ${LPI_PRO_U}/lpi_isakmp.o \
        ${LPI_PRO_U}/lpi_jedi.o \
        ${LPI_PRO_U}/lpi_jedi_academy.o \
        ${LPI_PRO_U}/lpi_kademlia.o \
        ${LPI_PRO_U}/lpi_kankan.o \
        ${LPI_PRO_U}/lpi_kaspersky.o \
        ${LPI_PRO_U}/lpi_kazaa.o \
        ${LPI_PRO_U}/lpi_kuguo.o \
        ${LPI_PRO_U}/lpi_l2tp.o \
        ${LPI_PRO_U}/lpi_lansync.o \
        ${LPI_PRO_U}/lpi_ldap_ad.o \
        ${LPI_PRO_U}/lpi_line_udp.o \
        ${LPI_PRO_U}/lpi_linkproof.o \
        ${LPI_PRO_U}/lpi_lol.o \
        ${LPI_PRO_U}/lpi_mdns.o \
        ${LPI_PRO_U}/lpi_merakicloud.o \
        ${LPI_PRO_U}/lpi_moh.o \
        ${LPI_PRO_U}/lpi_mp2p.o \
        ${LPI_PRO_U}/lpi_msn_cache.o \
        ${LPI_PRO_U}/lpi_msn_video.o \
        ${LPI_PRO_U}/lpi_msoffice_mac.o \
        ${LPI_PRO_U}/lpi_mta.o \
        ${LPI_PRO_U}/lpi_mystery_05.o \
        ${LPI_PRO_U}/lpi_mystery_0660.o \
        ${LPI_PRO_U}/lpi_mystery_0d.o \
        ${LPI_PRO_U}/lpi_mystery_45.o \
        ${LPI_PRO_U}/lpi_mystery_61_72.o \
        ${LPI_PRO_U}/lpi_mystery_8000.o \
        ${LPI_PRO_U}/lpi_mystery_99.o \
        ${LPI_PRO_U}/lpi_mystery_e9.o \
        ${LPI_PRO_U}/lpi_mystery_qq.o \
        ${LPI_PRO_U}/lpi_n2ping.o \
        ${LPI_PRO_U}/lpi_natpmp.o \
        ${LPI_PRO_U}/lpi_netbios.o \
        ${LPI_PRO_U}/lpi_netcat_cctv_udp.o \
        ${LPI_PRO_U}/lpi_netcore_scan.o \
        ${LPI_PRO_U}/lpi_netflow.o \
        ${LPI_PRO_U}/lpi_newerth.o \
        ${LPI_PRO_U}/lpi_nintendo.o \
        ${LPI_PRO_U}/lpi_noction.o \
        ${LPI_PRO_U}/lpi_noe.o \
        ${LPI_PRO_U}/lpi_nopayload.o \
        ${LPI_PRO_U}/lpi_norton.o \
        ${LPI_PRO_U}/lpi_ntp.o \
        ${LPI_PRO_U}/lpi_ntp_reflect.o \
        ${LPI_PRO_U}/lpi_nwn.o \
        ${LPI_PRO_U}/lpi_opaserv.o \
        ${LPI_PRO_U}/lpi_openvpn.o \
        ${LPI_PRO_U}/lpi_orbit.o \
        ${LPI_PRO_U}/lpi_overwatch.o \
        ${LPI_PRO_U}/lpi_pando.o \
        ${LPI_PRO_U}/lpi_panipani.o \
        ${LPI_PRO_U}/lpi_planetside2.o \
        ${LPI_PRO_U}/lpi_portmap_rpc.o \
        ${LPI_PRO_U}/lpi_pplive.o \
        ${LPI_PRO_U}/lpi_ppstream.o \
        ${LPI_PRO_U}/lpi_probable_gnutella.o \
        ${LPI_PRO_U}/lpi_ps4_remoteplay.o \
        ${LPI_PRO_U}/lpi_psn.o \
        ${LPI_PRO_U}/lpi_punkbuster.o \
        ${LPI_PRO_U}/lpi_pyzor.o \
        ${LPI_PRO_U}/lpi_qq.o \
        ${LPI_PRO_U}/lpi_qqlive.o \
        ${LPI_PRO_U}/lpi_qqpcmgr.o \
        ${LPI_PRO_U}/lpi_quake.o \
        ${LPI_PRO_U}/lpi_quic.o \
        ${LPI_PRO_U}/lpi_radius.o \
        ${LPI_PRO_U}/lpi_ramseydash.o \
        ${LPI_PRO_U}/lpi_rdp_udp.o \
        ${LPI_PRO_U}/lpi_real.o \
        ${LPI_PRO_U}/lpi_risingstorm.o \
        ${LPI_PRO_U}/lpi_roblox.o \
        ${LPI_PRO_U}/lpi_robocraft.o \
        ${LPI_PRO_U}/lpi_rtcp.o \
        ${LPI_PRO_U}/lpi_rtmfp.o \
        ${LPI_PRO_U}/lpi_rtp.o \
        ${LPI_PRO_U}/lpi_sanandreas_mp.o \
        ${LPI_PRO_U}/lpi_second_life.o \
        ${LPI_PRO_U}/lpi_serialnumberd.o \
        ${LPI_PRO_U}/lpi_sip.o \
        ${LPI_PRO_U}/lpi_skype.o \
        ${LPI_PRO_U}/lpi_slp.o \
        ${LPI_PRO_U}/lpi_smite.o \
        ${LPI_PRO_U}/lpi_snapvpn.o \
        ${LPI_PRO_U}/lpi_snmp.o \
        ${LPI_PRO_U}/lpi_sopcast.o \
        ${LPI_PRO_U}/lpi_spamfighter.o \
        ${LPI_PRO_U}/lpi_spotify_bcast.o \
        ${LPI_PRO_U}/lpi_sql_worm.o \
        ${LPI_PRO_U}/lpi_ssdp.o \
        ${LPI_PRO_U}/lpi_starcitizen.o \
        ${LPI_PRO_U}/lpi_starcraft.o \
        ${LPI_PRO_U}/lpi_starleaf.o \
        ${LPI_PRO_U}/lpi_steam.o \
        ${LPI_PRO_U}/lpi_steamfriends.o \
        ${LPI_PRO_U}/lpi_steam_inhomebroadcast.o \
        ${LPI_PRO_U}/lpi_steam_localbroadcast.o \
        ${LPI_PRO_U}/lpi_storm_worm.o \
        ${LPI_PRO_U}/lpi_stun.o \
        ${LPI_PRO_U}/lpi_syslog.o \
        ${LPI_PRO_U}/lpi_teamspeak.o \
        ${LPI_PRO_U}/lpi_teamviewer.o \
        ${LPI_PRO_U}/lpi_teredo.o \
        ${LPI_PRO_U}/lpi_tf2.o \
        ${LPI_PRO_U}/lpi_tftp.o \
        ${LPI_PRO_U}/lpi_thecrew.o \
        ${LPI_PRO_U}/lpi_thq.o \
        ${LPI_PRO_U}/lpi_torchlight2.o \
        ${LPI_PRO_U}/lpi_traceroute.o \
        ${LPI_PRO_U}/lpi_tremulous.o \
        ${LPI_PRO_U}/lpi_turbovpn.o \
        ${LPI_PRO_U}/lpi_tvants.o \
        ${LPI_PRO_U}/lpi_ubisoft_games.o \
        ${LPI_PRO_U}/lpi_umeye.o \
        ${LPI_PRO_U}/lpi_unreal.o \
        ${LPI_PRO_U}/lpi_ventrilo.o \
        ${LPI_PRO_U}/lpi_viber.o \
        ${LPI_PRO_U}/lpi_vivox.o \
        ${LPI_PRO_U}/lpi_vpnmaster.o \
        ${LPI_PRO_U}/lpi_vpnrobot_udp.o \
        ${LPI_PRO_U}/lpi_vxworks_exploit.o \
        ${LPI_PRO_U}/lpi_warthunder.o \
        ${LPI_PRO_U}/lpi_webex.o \
        ${LPI_PRO_U}/lpi_wechat_udp.o \
        ${LPI_PRO_U}/lpi_winmessage.o \
        ${LPI_PRO_U}/lpi_wolfet.o \
        ${LPI_PRO_U}/lpi_worm_22105.o \
        ${LPI_PRO_U}/lpi_xfire_p2p.o \
        ${LPI_PRO_U}/lpi_xlsp.o \
        ${LPI_PRO_U}/lpi_xunlei.o \
        ${LPI_PRO_U}/lpi_xunlei_jsq.o \
        ${LPI_PRO_U}/lpi_xunyou.o \
        ${LPI_PRO_U}/lpi_youdao_dict.o \
        ${LPI_PRO_U}/lpi_youku.o \
        ${LPI_PRO_U}/lpi_yy_udp.o \
        ${LPI_PRO_U}/lpi_zeroaccess_udp.o \
        ${LPI_PRO_U}/lpi_zoom.o \
		${NDPI_SRC}/lib/third_party/src/node.o \
		${NDPI_SRC}/lib/third_party/src/ahocorasick.o \
		${NDPI_SRC}/lib/third_party/src/libcache.o \
		${NDPI_SRC}/lib/third_party/src/hash.o \
		${NDPI_SRC}/lib/third_party/src/ndpi_patricia.o \
		${NDPI_SRC}/lib/ndpi_main.o \
		${NDPI_PRO}/afp.o \
		${NDPI_PRO}/ajp.o \
		${NDPI_PRO}/aimini.o \
		${NDPI_PRO}/amqp.o \
		${NDPI_PRO}/applejuice.o \
		${NDPI_PRO}/apple_push.o \
		${NDPI_PRO}/armagetron.o \
		${NDPI_PRO}/ayiya.o \
		${NDPI_PRO}/battlefield.o \
		${NDPI_PRO}/bgp.o \
		${NDPI_PRO}/bittorrent.o \
		${NDPI_PRO}/bjnp.o \
		${NDPI_PRO}/checkmk.o \
		${NDPI_PRO}/citrix.o \
		${NDPI_PRO}/ciscovpn.o \
		${NDPI_PRO}/coap.o \
		${NDPI_PRO}/collectd.o \
		${NDPI_PRO}/corba.o \
		${NDPI_PRO}/crossfire.o \
		${NDPI_PRO}/csgo.o \
		${NDPI_PRO}/dcerpc.o \
		${NDPI_PRO}/diameter.o \
		${NDPI_PRO}/dhcp.o \
		${NDPI_PRO}/dhcpv6.o \
		${NDPI_PRO}/directconnect.o \
		${NDPI_PRO}/directdownloadlink.o \
		${NDPI_PRO}/dns.o \
		${NDPI_PRO}/dofus.o \
		${NDPI_PRO}/drda.o \
		${NDPI_PRO}/dropbox.o \
		${NDPI_PRO}/eaq.o \
		${NDPI_PRO}/edonkey.o \
		${NDPI_PRO}/fasttrack.o \
		${NDPI_PRO}/fbzero.o \
		${NDPI_PRO}/fiesta.o \
		${NDPI_PRO}/fix.o \
		${NDPI_PRO}/florensia.o \
		${NDPI_PRO}/ftp_control.o \
		${NDPI_PRO}/ftp_data.o \
		${NDPI_PRO}/git.o \
		${NDPI_PRO}/gnutella.o \
		${NDPI_PRO}/gtp.o \
		${NDPI_PRO}/guildwars.o \
		${NDPI_PRO}/h323.o \
		${NDPI_PRO}/halflife2_and_mods.o \
		${NDPI_PRO}/hangout.o \
		${NDPI_PRO}/hep.o \
		${NDPI_PRO}/http.o \
		${NDPI_PRO}/http_activesync.o \
		${NDPI_PRO}/iax.o \
		${NDPI_PRO}/icecast.o \
		${NDPI_PRO}/ipp.o \
		${NDPI_PRO}/irc.o \
		${NDPI_PRO}/jabber.o \
		${NDPI_PRO}/kakaotalk_voice.o \
		${NDPI_PRO}/kerberos.o \
		${NDPI_PRO}/kontiki.o \
		${NDPI_PRO}/ldap.o \
		${NDPI_PRO}/lisp.o \
		${NDPI_PRO}/lotus_notes.o \
		${NDPI_PRO}/mail_imap.o \
		${NDPI_PRO}/mail_pop.o \
		${NDPI_PRO}/mail_smtp.o \
		${NDPI_PRO}/maplestory.o \
		${NDPI_PRO}/memcached.o \
		${NDPI_PRO}/mdns.o \
		${NDPI_PRO}/mgcp.o \
		${NDPI_PRO}/mpegts.o \
		${NDPI_PRO}/mqtt.o \
		${NDPI_PRO}/msn.o \
		${NDPI_PRO}/mssql_tds.o \
		${NDPI_PRO}/mysql.o \
		${NDPI_PRO}/netbios.o \
		${NDPI_PRO}/netflow.o \
		${NDPI_PRO}/nfs.o \
		${NDPI_PRO}/nintendo.o \
		${NDPI_PRO}/noe.o \
		${NDPI_PRO}/non_tcp_udp.o \
		${NDPI_PRO}/ntp.o \
		${NDPI_PRO}/openft.o \
		${NDPI_PRO}/openvpn.o \
		${NDPI_PRO}/oracle.o \
		${NDPI_PRO}/oscar.o \
        ${NDPI_PRO}/pando.o \
        ${NDPI_PRO}/megaco.o \
		${NDPI_PRO}/pcanywhere.o \
		${NDPI_PRO}/postgres.o \
		${NDPI_PRO}/pplive.o \
		${NDPI_PRO}/ppstream.o \
		${NDPI_PRO}/pptp.o \
		${NDPI_PRO}/qq.o \
		${NDPI_PRO}/quic.o \
		${NDPI_PRO}/radius.o \
		${NDPI_PRO}/rdp.o \
		${NDPI_PRO}/redis_net.o \
		${NDPI_PRO}/rsync.o \
		${NDPI_PRO}/rtp.o \
		${NDPI_PRO}/rtcp.o \
		${NDPI_PRO}/rtmp.o \
		${NDPI_PRO}/rtsp.o \
		${NDPI_PRO}/rx.o \
		${NDPI_PRO}/sflow.o \
		${NDPI_PRO}/shoutcast.o \
		${NDPI_PRO}/sip.o \
		${NDPI_PRO}/skinny.o \
		${NDPI_PRO}/skype.o \
		${NDPI_PRO}/smb.o \
		${NDPI_PRO}/smpp.o \
		${NDPI_PRO}/snmp.o \
		${NDPI_PRO}/socks45.o \
		${NDPI_PRO}/someip.o \
		${NDPI_PRO}/sopcast.o \
		${NDPI_PRO}/soulseek.o \
		${NDPI_PRO}/spotify.o \
		${NDPI_PRO}/ssdp.o \
		${NDPI_PRO}/ssh.o \
		${NDPI_PRO}/ssl.o \
		${NDPI_PRO}/starcraft.o \
		${NDPI_PRO}/stealthnet.o \
		${NDPI_PRO}/steam.o \
		${NDPI_PRO}/stun.o \
		${NDPI_PRO}/syslog.o \
		${NDPI_PRO}/teamviewer.o \
		${NDPI_PRO}/teamspeak.o \
		${NDPI_PRO}/telnet.o \
		${NDPI_PRO}/telegram.o \
		${NDPI_PRO}/teredo.o \
		${NDPI_PRO}/tftp.o \
		${NDPI_PRO}/thunder.o \
		${NDPI_PRO}/tinc.o \
		${NDPI_PRO}/tor.o \
		${NDPI_PRO}/tcp_udp.o \
		${NDPI_PRO}/tvants.o \
		${NDPI_PRO}/tvuplayer.o \
		${NDPI_PRO}/ubntac2.o \
		${NDPI_PRO}/usenet.o \
		${NDPI_PRO}/vhua.o \
		${NDPI_PRO}/viber.o \
		${NDPI_PRO}/vmware.o \
		${NDPI_PRO}/vnc.o \
		${NDPI_PRO}/whatsapp.o \
		${NDPI_PRO}/warcraft3.o \
		${NDPI_PRO}/whoisdas.o \
		${NDPI_PRO}/world_of_kung_fu.o \
		${NDPI_PRO}/world_of_warcraft.o \
		${NDPI_PRO}/xbox.o \
		${NDPI_PRO}/xdmcp.o \
		${NDPI_PRO}/yahoo.o \
		${NDPI_PRO}/zattoo.o \
		${NDPI_PRO}/zeromq.o

all:	modules

modules:
	make  -C ${KERNEL_DIR} M=$$PWD $@ $(MFLAGS);

modules_install:
	make -C ${KERNEL_DIR} M=$$PWD $@;
	depmod -a;
clean:
	make -C ${KERNEL_DIR} M=$$PWD $@;
	rm -rf modules.order
distclean:
	find ../../src/lib/ -type f \( -name \*.o -o -name \*.cmd \) | xargs -r rm
