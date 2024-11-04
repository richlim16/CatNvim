#include "nvim.h"

int luaopen_init(lua_State *L) {
  char *lazypath = concat_str(get_xdg_home(1), "/lazy/lazy.nvim/");
  // if (os_isdir(lazypath) == false) {
  //   system(concat_str("git clone --filter=blob:none "
  //                     "https://github.com/folke/lazy.nvim.git --branch=stable
  //                     ", lazypath));
  // }
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
            mocha = {
              base = '#1b1424',
              mantle = '#000000',
              crust = '#202252',
            },
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
        },

        {
          'mg979/vim-visual-multi',
          lazy = false,
        },
      },
      install = {
        colorscheme = { 'catppuccin' }
      }
    }));
  return 1;
}
