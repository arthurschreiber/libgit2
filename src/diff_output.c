#include "git2/oid.h"
	int error;
			info->error = -1;
		else if (read_next_int(&scan, &range.old_start) < 0)
			info->error = -1;
		else if (*scan == ',' && read_next_int(&scan, &range.old_lines) < 0)
			info->error = -1;
		else if (read_next_int(&scan, &range.new_start) < 0)
			info->error = -1;
		else if (*scan == ',' && read_next_int(&scan, &range.new_lines) < 0)
			info->error = -1;
		else if (range.old_start < 0 || range.new_start < 0)
			info->error = -1;
		else {
			memcpy(&info->range, &range, sizeof(git_diff_range));

			if (info->hunk_cb(
					info->cb_data, info->delta, &range, bufs[0].ptr, bufs[0].size))
				info->error = GIT_EUSER;
		}
				info->cb_data, info->delta, &info->range, origin, bufs[1].ptr, bufs[1].size))
			info->error = GIT_EUSER;
		else if (len == 3) {
			if (info->line_cb(
					info->cb_data, info->delta, &info->range, origin, bufs[2].ptr, bufs[2].size))
				info->error = GIT_EUSER;
	return info->error;
		delta->new_file.flags |= (delta->old_file.flags & BINARY_DIFF_FLAGS);
	memset(&info, 0, sizeof(info));
				delta->new_file.flags |= GIT_DIFF_FILE_VALID_OID;
		if (file_cb != NULL &&
			file_cb(data, delta, (float)info.index / diff->deltas.length))
		{
			error = GIT_EUSER;
			goto cleanup;
		error = info.error;
	if (pi->print_cb(pi->cb_data, delta, NULL, GIT_DIFF_LINE_FILE_HDR,
			git_buf_cstr(pi->buf), git_buf_len(pi->buf)))
		return GIT_EUSER;

	return 0;
    if (pi->print_cb(pi->cb_data, delta, NULL, GIT_DIFF_LINE_FILE_HDR, git_buf_cstr(pi->buf), git_buf_len(pi->buf)))
		return GIT_EUSER;
	if (pi->print_cb(pi->cb_data, delta, NULL, GIT_DIFF_LINE_BINARY,
			git_buf_cstr(pi->buf), git_buf_len(pi->buf)))
		return GIT_EUSER;

	return 0;
	if (pi->print_cb(pi->cb_data, d, r, GIT_DIFF_LINE_HUNK_HDR,
			git_buf_cstr(pi->buf), git_buf_len(pi->buf)))
		return GIT_EUSER;

	return 0;
	if (pi->print_cb(pi->cb_data, delta, range, line_origin,
			git_buf_cstr(pi->buf), git_buf_len(pi->buf)))
		return GIT_EUSER;

	return 0;
int git_diff_entrycount(git_diff_list *diff, int delta_t)
{
	int count = 0;
	unsigned int i;
	git_diff_delta *delta;

	assert(diff);

	if (delta_t < 0)
		return diff->deltas.length;

	git_vector_foreach(&diff->deltas, i, delta) {
		if (delta->status == (git_delta_t)delta_t)
			count++;
	}

	return count;
}

	if (file_cb != NULL && file_cb(cb_data, &delta, 1))
		return GIT_EUSER;
	memset(&info, 0, sizeof(info));
	return info.error;