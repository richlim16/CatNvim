#include "nvim.h"

int luaopen_init(lua_State *L) {
  char *lazypath = concat_str(get_xdg_home(1), "/lazy/lazy.nvim/");
  if (os_isdir(lazypath) == false) {
    system(concat_str("git clone --filter=blob:none "
                      "https://github.com/folke/lazy.nvim.git --branch=stable ",
                      lazypath));
  }
  opt("runtimepath", runtimepath_default(false), lazypath);
  // clang-format off
  require_setup("lazy", LUA_TABLE(
    {
      spec = {
        {
          'catppuccin/nvim',
          name = 'catppuccin',
          opts = {
            color_overrides = {
            },
          }
        },
        {
          "folke/tokyonight.nvim",
          name = 'tokyonight',
          lazy = false,
          priority = 1000,
        },

        {
          'LazyVim/LazyVim',
          import = 'lazyvim.plugins',
          // opts = { colorscheme = 'catppuccin' }
          opts = { colorscheme = 'tokyonight' }
        }
      },
      install = {
        colorscheme = { 'catppuccin' }
      }
    }));
  return 1;
}
