set_config('cflags', '-std=c17 -O2 -g3 -Wall -Werror -pedantic -fsanitize=address,undefined -Wformat -Werror=format-security -Werror=array-bounds')
set_config('ldflags', '-fsanitize=address,undefined -fpie -Wl,-pie')

on_load(function (toolchain)
    import('lib.detect.find_package')
    local p = find_package('libunistring')
    if p then
        toolchain:add('defines', 'USE_LIBUNISTRING')
        toolchain:add(p)
    end
end)


target('client-naive')
    set_kind('binary')
    add_files('client-naive.c')

target('server-iterative-naive')
    set_kind('binary')
    add_files('server-iterative-naive.c')

target('client-td')
    set_kind('binary')
    add_files('client-td.c', 'rxb.c', 'utils.c')

target('server-concurrent-td')
    set_kind('binary')
    add_files('server-concurrent-td.c', 'rxb.c', 'utils.c')

