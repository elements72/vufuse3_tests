#define FUSE_USE_VERSION 30
#include <fuse3/fuse.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

// Path of the unreal folder
int unreal_len;

static int op_getattr(const char *path, struct stat *stbuf, struct fuse_file_info *fi)
{
    struct stat stats;
    if(stat(path, &stats) == 0)
        *stbuf = stats;
    else
        return -ENOENT;
    return 0;
}

static int op_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi,
                      enum fuse_readdir_flags flags)
{
    DIR *d;
    struct dirent *dir;
    if(strcmp(path, "/") == 0)
        d = opendir("/");
    else 
        d = opendir(path);
    while ((dir = readdir(d)) != NULL) {
        filler(buf, dir->d_name, NULL, 0, flags);
    }
    return 0;
}

static const struct fuse_operations unreal_ops = {
    .getattr = op_getattr,
    .readdir = op_readdir,
};

int main(int argc, char *argv[]) {
    // printk("Unreal len: %d", unreal_len);
    return fuse_main(argc, argv, &unreal_ops, NULL);
}