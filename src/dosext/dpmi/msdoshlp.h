#ifndef MSDOSHLP_H
#define MSDOSHLP_H

enum MsdOpIds { NONE, API_CALL, API_WINOS2_CALL, XMS_CALL };

extern int msdos_pre_pm(struct sigcontext *scp,
	struct RealModeCallStructure *rmreg);
extern void msdos_post_pm(int offs,
	const struct RealModeCallStructure *rmreg);
extern void msdos_pm_call(struct sigcontext *scp, int is_32);

extern struct pmaddr_s get_pmcb_handler(void (*handler)(struct sigcontext *,
	const struct RealModeCallStructure *, int, void *),
	void *arg,
	void (*ret_handler)(struct sigcontext *,
	struct RealModeCallStructure *, int),
	int num);
extern struct pmaddr_s get_pm_handler(enum MsdOpIds id,
	void (*handler)(struct sigcontext *, void *), void *arg);
extern struct pmaddr_s get_pmrm_handler(enum MsdOpIds id, void (*handler)(
	const struct sigcontext *, struct RealModeCallStructure *, void *),
	void *arg,
	void (*done_handler)(const struct RealModeCallStructure *, void *),
	void (*ret_handler)(
	struct sigcontext *, void *));
extern far_t get_lr_helper(far_t rmcb);
extern far_t get_lw_helper(far_t rmcb);
extern far_t get_exec_helper(void);

#endif
