/*
 * Function prototypes for the malloc user level routines.
 *
 * Copyright 2000 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via http://www.dmalloc.com/
 *
 * $Id: malloc.h,v 1.30 2000/04/18 01:53:58 gray Exp $
 */

#ifndef __MALLOC_H__
#define __MALLOC_H__

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * shutdown memory-allocation module, provide statistics if necessary
 * NOTE: called by way of leap routine in dmalloc_lp.c
 */
extern
void	_dmalloc_shutdown(void);

#if FINI_DMALLOC
/*
 * Automatic OSF function to close dmalloc.  Pretty cool OS/compiler
 * hack.  By default it is not necessary because we use atexit() and
 * on_exit() to register the close functions.  These are more
 * portable.
 */
extern
void	__fini_dmalloc();
#endif /* if FINI_DMALLOC */

/*
 * Allocate and return a SIZE block of bytes.  FUNC_ID contains the
 * type of function.  If we are aligning our malloc then ALIGNMENT is
 * greater than 0.  Returns 0L on error.
 */
extern
DMALLOC_PNT	_loc_malloc(const char *file, const int line,
			    const DMALLOC_SIZE size, const int func_id,
			    const DMALLOC_SIZE alignment);

/*
 * Resizes OLD_PNT to NEW_SIZE bytes and return the new space after
 * either copying all of OLD_PNT to the new area or truncating.  If
 * OLD_PNT is 0L then it will do the equivalent of malloc(NEW_SIZE).
 * If NEW_SIZE is 0 and OLD_PNT is not 0L then it will do the
 * equivalent of free(OLD_PNT) and will return 0L.  If the RECALLOC_B
 * flag is enabled, it will zero any new memory.  Returns 0L on error.
 */
extern
DMALLOC_PNT	_loc_realloc(const char *file, const int line,
			     DMALLOC_PNT old_pnt, DMALLOC_SIZE new_size,
			     const int func_id);

/*
 * release PNT in the heap, returning FREE_ERROR, FREE_NOERROR.
 */
extern
int	_loc_free(const char *file, const int line, DMALLOC_PNT pnt);

/*
 * allocate and return a SIZE block of bytes.  returns 0L on error.
 */
extern
DMALLOC_PNT	malloc(DMALLOC_SIZE size);

/*
 * allocate and return a block of _zeroed_ bytes able to hold
 * NUM_ELEMENTS, each element contains SIZE bytes.  returns 0L on
 * error.
 */
extern
DMALLOC_PNT	calloc(DMALLOC_SIZE num_elements, DMALLOC_SIZE size);

/*
 * Resizes OLD_PNT to NEW_SIZE bytes and return the new space after
 * either copying all of OLD_PNT to the new area or truncating.  If
 * OLD_PNT is 0L then it will do the equivalent of malloc(NEW_SIZE).
 * If NEW_SIZE is 0 and OLD_PNT is not 0L then it will do the
 * equivalent of free(OLD_PNT) and will return 0L.  Returns 0L on
 * error.
 */
extern
DMALLOC_PNT	realloc(DMALLOC_PNT old_pnt, DMALLOC_SIZE new_size);

/*
 * Resizes OLD_PNT to NEW_SIZE bytes and return the new space after
 * either copying all of OLD_PNT to the new area or truncating.  If
 * OLD_PNT is 0L then it will do the equivalent of malloc(NEW_SIZE).
 * If NEW_SIZE is 0 and OLD_PNT is not 0L then it will do the
 * equivalent of free(OLD_PNT) and will return 0L.  Any extended
 * memory space will be zeroed like calloc.  Returns 0L on error.
 */
extern
DMALLOC_PNT	recalloc(DMALLOC_PNT old_pnt, DMALLOC_SIZE new_size);

/*
 * Allocate and return a SIZE block of bytes that has been aligned to
 * ALIGNMENT bytes.  ALIGNMENT must be a power of two and must be less
 * than or equal to the block-size.  Returns 0L on error.
 */
extern
DMALLOC_PNT	memalign(DMALLOC_SIZE alignment, DMALLOC_SIZE size);

/*
 * Allocate and return a SIZE block of bytes that has been aligned to
 * a page-size.  Returns 0L on error.
 */
extern
DMALLOC_PNT	valloc(DMALLOC_SIZE size);

#ifndef DMALLOC_STRDUP_MACRO
/*
 * Allocate and return a block of bytes that contains the string STR
 * including the \0.  Returns 0L on error.
 */
extern
char	*strdup(const char *str);
#endif /* ifndef DMALLOC_STRDUP_MACRO */

/*
 * release PNT in the heap, returning FREE_ERROR, FREE_NOERROR or void
 * depending on whether STDC is defined by your compiler.
 */
extern
DMALLOC_FREE_RET	free(DMALLOC_PNT pnt);

/*
 * same as free PNT
 */
extern
DMALLOC_FREE_RET	cfree(DMALLOC_PNT pnt);

/*
 * log the heap structure plus information on the blocks if necessary.
 * NOTE: called by way of leap routine in dmalloc_lp.c
 */
extern
void	_dmalloc_log_heap_map(const char *file, const int line);

/*
 * dump dmalloc statistics to logfile
 * NOTE: called by way of leap routine in dmalloc_lp.c
 */
extern
void	_dmalloc_log_stats(const char *file, const int line);

/*
 * dump unfreed-memory info to logfile
 * NOTE: called by way of leap routine in dmalloc_lp.c
 */
extern
void	_dmalloc_log_unfreed(const char *file, const int line);

/*
 * verify pointer PNT, if PNT is 0 then check the entire heap.
 * NOTE: called by way of leap routine in dmalloc_lp.c
 * returns MALLOC_VERIFY_ERROR or MALLOC_VERIFY_NOERROR
 */
extern
int	_dmalloc_verify(const DMALLOC_PNT pnt);

/*
 * Set the global debug functionality FLAGS (0 to disable all
 * debugging).
 *
 * NOTE: you cannot set certain flags such as fence-post or free-space
 * checking with this function.
 */
extern
void	_dmalloc_debug(const int flags);

/*
 * returns the current debug functionality flags.  this allows you to
 * save a dmalloc library state to be restored later.
 */
extern
int	_dmalloc_debug_current(void);

/*
 * examine pointer PNT and returns SIZE, and FILE / LINE info on it,
 * or return-address RET_ADDR if any of the pointers are not 0L.
 * if FILE returns 0L then RET_ATTR may have a value and vice versa.
 * returns NOERROR or ERROR depending on whether PNT is good or not
 */
extern
int	_dmalloc_examine(const char *file, const int line,
			 const DMALLOC_PNT pnt, DMALLOC_SIZE *size_p,
			 char **file_p, unsigned int *line_p,
			 DMALLOC_PNT *ret_attr_p);

/*
 * Register an allocation tracking function which will be called each
 * time an allocation occurs.  Pass in NULL to disable.
 */
extern
void	_dmalloc_track(const dmalloc_track_t track_func);

/*
 * Return to the caller the current ``mark'' which can be used later
 * to dmalloc_log_changed pointers since this point.  Multiple marks
 * can be saved and used.
 */
extern
unsigned long	_dmalloc_mark(void);

/*
 * Dump the pointers that have changed since the mark which was
 * returned by dmalloc_mark.  If not_freed_b is set to non-0 then log
 * the new pointers that are non-freed.  If free_b is set to non-0
 * then log the new pointers that are freed.  If details_b set to
 * non-0 then dump the individual pointers that have changed otherwise
 * just dump the summaries.
 */
extern
void	_dmalloc_log_changed(const char *file, const int line,
			     const unsigned long mark, const int not_freed_b,
			     const int free_b, const int details_b);

/*
 * Dmalloc version of strerror to return the string version of
 * ERROR_NUM.  Returns an invaid errno string if ERROR_NUM is
 * out-of-range.
 */
extern
const char	*_dmalloc_strerror(const int error_num);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __MALLOC_H__ */
