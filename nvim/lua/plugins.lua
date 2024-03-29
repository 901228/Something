-- local packer_exists = pcall(vim.cmd, [[packadd packer.nvim]])
vim.cmd [[packadd packer.nvim]]

return require("packer").startup(function()
    use 'wbthomason/packer.nvim'
    use {
        'nvim-tree/nvim-tree.lua',
        requires = 'nvim-tree/nvim-web-devicons',
        -- cmd = { "NvimTreeToggle", "NvimTreeRefresh", "NvimTreeFocus" },
        opt = true,
        config = function() require'nvim-tree'.setup {} end
    }
    use { 'akinsho/bufferline.nvim', requires = 'kyazdani42/nvim-web-devicons' }
    use { 'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' }
    use 'glepnir/zephyr-nvim'
    use {
        'nvim-telescope/telescope.nvim',
        tag = '0.1.1',
        requires = 'nvim-lua/plenary.nvim'
    }
    use {
        'windwp/nvim-autopairs',
        config = function() require('nvim-autopairs').setup {} end
    }
    use {
        'numToStr/Comment.nvim',
        config = function() require('Comment').setup {} end
    }
    use {
        'kylechui/nvim-surround',
        tag = "*", -- Use for stability; omit to use `main` branch for the latest features
        config = function() require("nvim-surround").setup {} end
    }
    use {
        'nvim-lualine/lualine.nvim',
        requires = { 'nvim-tree/nvim-web-devicons', opt = true }
    }
    use {
        'akinsho/toggleterm.nvim',
        tag = '*',
        config = function() require('toggleterm').setup {} end
    }

    ---- LSP ----
    use {
        'williamboman/mason.nvim',
        'williamboman/mason-lspconfig.nvim',
        'neovim/nvim-lspconfig',
    }
    -- nvim-cmp
    use 'hrsh7th/cmp-nvim-lsp' -- { name = nvim_lsp }
    use 'hrsh7th/cmp-buffer'   -- { name = 'buffer' },
    use 'hrsh7th/cmp-path'     -- { name = 'path' }
    use 'hrsh7th/cmp-cmdline'  -- { name = 'cmdline' }
    use 'hrsh7th/nvim-cmp'
    -- snippets
    use 'hrsh7th/cmp-nvim-lsp-signature-help' -- { name = 'nvim_lsp_signature_help' }
    use 'L3MON4D3/LuaSnip'
    use 'saadparwaiz1/cmp_luasnip'
    use 'hrsh7th/cmp-vsnip'    -- { name = 'vsnip' }
    use 'hrsh7th/vim-vsnip'
    use 'rafamadriz/friendly-snippets'
    -- lspkind
    use 'onsails/lspkind-nvim'

    --- enhancement ---
    -- Lua
    use { 'folke/neodev.nvim', config = function() require('neodev').setup({}) end }
    -- Json
    use 'b0o/schemastore.nvim'

    ---- UI ----
    -- alpha
    use {
        'goolord/alpha-nvim',
        requires = 'nvim-tree/nvim-web-devicons',
    }
    -- ascii arts
    use {
        'MaximilianLloyd/ascii.nvim',
        requires = 'MunifTanjim/nui.nvim'
    }
    -- symbol table
    -- use 'simrat39/symbols-outline.nvim'
    -- pretty list of LSP, quickfix, telescope ...
    use {
        'folke/trouble.nvim',
        requires = 'nvim-tree/nvim-web-devicons',
        config = function() require('trouble').setup {} end
    }

end)
