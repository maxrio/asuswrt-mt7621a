#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <bcmnvram.h>
#include <bcmdevs.h>
#include "shared.h"


struct model_s {
	char *pid;
	int model;
};

static const struct model_s model_list[] = {
#if defined(RTCONFIG_REALTEK)
	{ "RP-AC68U",   MODEL_RPAC68U   },
	{ "RP-AC53",	MODEL_RPAC53	},
	{ "RP-AC55",	MODEL_RPAC55	},
#elif defined(RTCONFIG_RALINK)
#ifdef RTCONFIG_DSL
	{ "DSL-N55U",	MODEL_DSLN55U	},
	{ "DSL-N55U-B",	MODEL_DSLN55U	},
#endif
	{ "EA-N66",	MODEL_EAN66	},
	{ "RT-N11P",	MODEL_RTN11P	},
	{ "RT-N300",	MODEL_RTN300	},
	{ "RT-N13U",	MODEL_RTN13U	},
	{ "RT-N14U",	MODEL_RTN14U	},
	{ "RT-AC52U",	MODEL_RTAC52U	},
	{ "RT-AC51U",	MODEL_RTAC51U	},
	{ "RT-N54U",	MODEL_RTN54U	},
	{ "RT-AC54U",	MODEL_RTAC54U	},
	{ "RT-N56UB1",	MODEL_RTN56UB1	},
	{ "RT-N56UB2",	MODEL_RTN56UB2	},
	{ "RT-N36U3",	MODEL_RTN36U3	},
	{ "RT-N56U",	MODEL_RTN56U	},
	{ "RT-N65U",	MODEL_RTN65U	},
	{ "RT-N67U",	MODEL_RTN67U	},
	{ "RT-AC1200HP",MODEL_RTAC1200HP},
	{ "RT-AC1200",	MODEL_RTAC1200	},
	{ "RT-N600",	MODEL_RTAC1200	},
	{ "RT-AC1200GA1",MODEL_RTAC1200GA1	},
	{ "RT-AC1200GU",MODEL_RTAC1200GU	},
	{ "RT-AC51U+",	MODEL_RTAC51UP	},
	{ "RT-AC53",	MODEL_RTAC53	},
	{ "RT-N11P_B1", MODEL_RTN11P_B1},
	{ "RT-N10P_V3", MODEL_RTN11P_B1},
	{ "RP-AC87", MODEL_RPAC87},	
#if defined(RTMIR3G)
	{ "RT-MIR3G", MODEL_RTMIR3G},
#elif defined(RTMIR3P)
	{ "RT-MIR3P", MODEL_RTMIR3P},
#elif defined(RTMIR4A)
	{ "RT-MIR4A", MODEL_RTMIR4A},
#elif defined(RTRM2100)
	{ "RT-RM2100", MODEL_RTRM2100},
#elif defined(RTR2100)
	{ "RT-R2100", MODEL_RTR2100},
#elif defined(RTNEWIFI2)
	{ "RT-NEWIFI2", MODEL_RTNEWIFI2},
#elif defined(RTNEWIFI3)
	{ "RT-NEWIFI3", MODEL_RTNEWIFI3},
#elif defined(RTHIWIFI4)
	{ "RT-HIWIFI4", MODEL_RTHIWIFI4},
#else
	{ "RT-AC85U", MODEL_RTAC85U},
#endif
	{ "RT-AC85P", MODEL_RTAC85P},
	{ "RT-ACRH26", MODEL_RTACRH26},
	{ "RT-AC65U", MODEL_RTAC85U},
	{ "RT-N800HP",  MODEL_RTN800HP},
#elif defined(RTCONFIG_QCA)
	{ "RT-AC55U",	MODEL_RTAC55U	},
	{ "RT-AC55UHP",	MODEL_RTAC55UHP	},
	{ "4G-AC55U",	MODEL_RT4GAC55U	},
	{ "RT-N19",	MODEL_RTN19	},
	{ "RT-AC59U",	MODEL_RTAC59U	},
	{ "PL-N12",	MODEL_PLN12	},
	{ "PL-AC56",	MODEL_PLAC56	},
	{ "PL-AC66U",	MODEL_PLAC66U	},
	{ "RP-AC66",	MODEL_RPAC66	},
	{ "RP-AC51",	MODEL_RPAC51	},
	{ "RT-AC58U",	MODEL_RTAC58U	},
	{ "4G-AC53U",	MODEL_RT4GAC53U	},
	{ "RT-AC82U",	MODEL_RTAC82U	},
	{ "MAP-AC1300",	MODEL_MAPAC1300	},
	{ "MAP-AC2200",	MODEL_MAPAC2200	},
	{ "VZW-AC1300",	MODEL_VZWAC1300	},
	{ "MAP-AC1750",	MODEL_MAPAC1750	},
	{ "MAP-AC3000",	MODEL_MAPAC3000	},
	{ "RT-AC88N",	MODEL_RTAC88N	},
	{ "BRT-AC828",	MODEL_BRTAC828},
	{ "RT-AC88S",	MODEL_RTAC88S	},
	{ "RT-AD7200",	MODEL_RTAD7200	},
	{ "GT-AX6000",	MODEL_GTAX6000	},
	{ "GT-AX6000N",	MODEL_GTAX6000N	},
	{ "GT-AX6000S",	MODEL_GTAX6000S	},
#elif defined(RTCONFIG_ALPINE)
	{ "GT-AC9600",	MODEL_GTAC9600	},
#elif defined(RTCONFIG_LANTIQ)
	{ "BLUECAVE",	MODEL_BLUECAVE	},
	{ "BLUE_CAVE",	MODEL_BLUECAVE	},
#else
	{ "RT-N66U",	MODEL_RTN66U	},
	{ "RT-AC56S",	MODEL_RTAC56S	},
	{ "RT-AC56U",	MODEL_RTAC56U	},
	{ "RT-AC66U",	MODEL_RTAC66U	},
#ifdef RT4GAC68U
	{ "4G-AC68U",	MODEL_RTAC68U	},
#endif
	{ "RT-AC68U",	MODEL_RTAC68U	},
	{ "RT-AC68A",	MODEL_RTAC68U	},
	{ "RT-AC87U",	MODEL_RTAC87U	},
	{ "RT-AC53U",	MODEL_RTAC53U	},
	{ "RT-AC3200",	MODEL_RTAC3200	},
	{ "RT-AC88U",	MODEL_RTAC88U	},
	{ "RT-AC86U",	MODEL_RTAC86U	},
	{ "AC2900",	MODEL_RTAC86U	},
	{ "RT-AC3100",	MODEL_RTAC3100	},
	{ "RT-AC5300",	MODEL_RTAC5300	},
	{ "GT-AC5300",	MODEL_GTAC5300	},
	{ "RT-N53",	MODEL_RTN53	},
	{ "RT-N16",	MODEL_RTN16	},
	{ "RT-N18U",	MODEL_RTN18U	},
	{ "RT-N15U",	MODEL_RTN15U	},
	{ "RT-N12",	MODEL_RTN12	},
	{ "RT-N12B1",	MODEL_RTN12B1	},
	{ "RT-N12C1",	MODEL_RTN12C1	},
	{ "RT-N12D1",	MODEL_RTN12D1	},
	{ "RT-N12VP",	MODEL_RTN12VP	},
	{ "RT-N12HP",	MODEL_RTN12HP	},
	{ "RT-N12HP_B1",	MODEL_RTN12HP_B1	},
	{ "AP-N12",	MODEL_APN12	},
	{ "AP-N12HP",	MODEL_APN12HP	},
	{ "RT-N10U",	MODEL_RTN10U	},
	{ "RT-N14UHP",	MODEL_RTN14UHP	},
	{ "RT-N10+",	MODEL_RTN10P	},
	{ "RT-N10P",	MODEL_RTN10P	},
	{ "RT-N10D1",	MODEL_RTN10D1	},
	{ "RT-N10PV2",	MODEL_RTN10PV2	},
	{ "DSL-AC68U",	MODEL_DSLAC68U	},
	{ "RT-AC1200G", MODEL_RTAC1200G	},
	{ "RT-AC1200G+", MODEL_RTAC1200GP},
#endif	/* !RTCONFIG_RALINK */
	{ NULL, 0 },
};

#if defined(RTCONFIG_RALINK)
#elif defined(RTCONFIG_QCA)
#else
static int get_model_by_hw(void)
{
	char *hw_version = nvram_safe_get("hardware_version");

	if (strncmp(hw_version, "RTN12", 5) == 0) {
		if (strncmp(hw_version, "RTN12B1", 7) == 0)
			return MODEL_RTN12B1;
		if (strncmp(hw_version, "RTN12C1", 7) == 0)
			return MODEL_RTN12C1;
		if (strncmp(hw_version, "RTN12D1", 7) == 0)
			return MODEL_RTN12D1;
		if (strncmp(hw_version, "RTN12VP", 7) == 0)
			return MODEL_RTN12VP;
		if (strncmp(hw_version, "RTN12HP_B1", 10) == 0)
			return MODEL_RTN12HP_B1;
		if (strncmp(hw_version, "RTN12HP", 7) == 0)
			return MODEL_RTN12HP;
		if (strncmp(hw_version, "APN12HP", 7) == 0)
			return MODEL_APN12HP;
		return MODEL_RTN12;
	} else if (strncmp(hw_version, "APN12", 5) == 0) {
		if (strncmp(hw_version, "APN12HP", 7) == 0)
			return MODEL_APN12HP;
		return MODEL_APN12;
	}
	return MODEL_UNKNOWN;
}
#endif

#define BLV_MAX 4
#define BL_VERSION(a,b,c,d) (((a) << 12) + ((b) << 8) + ((c) << 4) + (d))

int get_blver(char *bls) {
	int bv[BLV_MAX], blver=0, i=0;
	char *tok, *delim = ".";
	char buf[32], *bp=NULL;

	memset(buf, 0, sizeof(buf));
	if(bls)
		strcpy(buf, bls);
	bp = buf;
	while((tok = strsep((char**)&bp, delim)))
		if(i < BLV_MAX)
			bv[i++] = atoi(tok);

	blver = BL_VERSION(bv[0], bv[1], bv[2], bv[3]);

	return blver;
}

int get_fwver(char *buildno, char *extendno) {
	
	return atoi(buildno)*100000 + atoi(extendno);
}

/* returns MODEL ID
 * result is cached for safe multiple use */
int get_model(void)
{
#if defined(RTMIR3G)
	return MODEL_RTMIR3G;
#elif defined(RTMIR3P)
	return MODEL_RTMIR3P;
#elif defined(RTMIR4A)
	return MODEL_RTMIR4A;
#elif defined(RTRM2100)
	return MODEL_RTRM2100;
#elif defined(RTR2100)
	return MODEL_RTR2100;
#elif defined(RTNEWIFI2)
	return MODEL_RTNEWIFI2;
#elif defined(RTNEWIFI3)
	return MODEL_RTNEWIFI3;
#elif defined(RTHIWIFI4)
	return MODEL_RTHIWIFI4;
#endif
	static int model = MODEL_UNKNOWN;
	char *pid;
	const struct model_s *p;

	if (model != MODEL_UNKNOWN)
		return model;

	pid = nvram_safe_get("productid");
	for (p = &model_list[0]; p->pid; ++p) {
		if (!strcmp(pid, p->pid)) {
			model = p->model;
			break;
		}
	}
	
#ifdef RTCONFIG_REALTEK
	if(model==MODEL_UNKNOWN || !pid[0]) {
	#ifdef RTCONFIG_RTL819X
		nvram_set("productid", "RT-RTL8881A");
		nvram_set("productid", "RP-AC53");
	#else
		nvram_set("productid", "RT-RTL8198C");
		nvram_set("productid", "RP-AC68U");//bruce
	#endif
	}
	cprintf("%s:%d current productid is %s\n",__FILE__,__LINE__,nvram_get("productid"));
#endif

#if defined(RTCONFIG_RALINK)
#elif defined(RTCONFIG_QCA)
#else
	if (model == MODEL_RTN12)
		model = get_model_by_hw();
	if (model == MODEL_APN12)
		model = get_model_by_hw();
#endif
	return model;
}

#if defined(RTCONFIG_RALINK)
#elif defined(RTCONFIG_QCA)
#else
/* returns product id */
char *get_modelid(int model)
{
	char *pid = "unknown";
	const struct model_s *p;

	for (p = &model_list[0]; p->pid; ++p) {
		if (model == p->model) {
			pid = p->pid;
			break;
		}
	}
	return pid;
}
#endif

/* returns SWITCH ID
 * result is cached for safe multiple use */
int get_switch(void)
{
	static int sw_model = SWITCH_UNKNOWN;

	if (sw_model != SWITCH_UNKNOWN)
		return sw_model;

	sw_model = get_switch_model();
	return sw_model;
}
