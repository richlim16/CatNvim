local map = vim.keymap.set

map("ca", "W", "SudaWrite")
map("n", "<A-.>", ":BufferLineCycleNext <CR>")
map("n", "<A->>", ":BufferLineMoveNext <CR>")
map("n", "<A-,>", ":BufferLineCyclePrev <CR>")
map("n", "<A-<>", ":BufferLineMovePrev <CR>")
map("n", "<A-d>", ":bp|sp|bn|bd! <CR>")

map("t", "<C-j>", "<C-\\><C-n><C-w>w") --" window down"
map("t", "<C-k>", "<C-\\><C-n><C-w>W") --" window up"

-- Center cursor
map("n", "<C-d>", "<C-d>zz")

map("n", "<A-h>", "<c-w>5<")
map("n", "<A-l>", "<C-w>5>")
map("n", "<A-H>", "<c-w>-")
map("n", "<A-L>", "<c-w>+")

-- nvimtree
map("n", "<C-n>", ":NvimTreeToggle<CR>")

-- telescope
map("n", "<leader>fd", ":Telescope find_files <CR>")
map("n", "<leader>fw", ":Telescope live_grep <CR>")

-- toggleterm
map("t", "<esc>", "<C-\\><C-N>", { nowait = true }) --"	escape terminal mode"
map("n", "<C-\\>", "<cmd> ToggleTerm direction=horizontal<CR>") --"	new horizontal term"
map("t", "<C-\\>", "<C-\\><C-n>:ToggleTerm direction=horizontal<CR>") --"	new horizontal term"
