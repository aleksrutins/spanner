#include "lua_wrapper.hpp"
#include "package.hpp"

Package::Package(std::string path) {
    this->path = path;
    this->resolved = false;
}

void Package::resolve() {
    if(this->resolved) {
        return;
    }
    this->resolved = true;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    run_file(L, this->path);
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "name");
    this->name = lua_tostring(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, -1, "version");
    this->version = lua_tostring(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, -1, "dependencies");
    lua_pushnil(L);
    while(lua_next(L, -2) != 0) {
        this->dependencies.push_back(Package(lua_tostring(L, -1)));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    lua_close(L);
}