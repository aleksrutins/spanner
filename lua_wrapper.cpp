#include <lua.hpp>
#include <string>

using namespace std;

void run_script(lua_State *L, string script) {
    if(luaL_dostring(L, script.c_str())) {
        fprintf(stderr, "%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
}

void run_file(lua_State *L, string filename) {
    if(luaL_dofile(L, filename.c_str())) {
        fprintf(stderr, "%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
}
