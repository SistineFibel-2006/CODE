(package-initialize)
(load-file "~/.emacs.rc/rc.el")

(menu-bar-mode 0)
(tool-bar-mode 0)
(scroll-bar-mode 0)
(column-number-mode 1)
(global-display-line-numbers-mode)
(ido-mode 1)
(ido-everywhere 1)
(add-to-list 'default-frame-alist `(font . "Fira Code Retina"))

(rc/require-theme 'gruber-darker)
(with-eval-after-load 'org (global-org-modern-mode))
;;(vertico-posframe-mode 1)
;;(vertico-reverse-mode -1)
(ivy-posframe-mode 1)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-safe-themes
   '("e13beeb34b932f309fb2c360a04a460821ca99fe58f69e65557d6c1b10ba18c7"
     default))
 '(display-line-numbers-type 'relative)
 '(inhibit-startup-screen t)
 '(package-selected-packages
   '(dap-mode dash-functional gruber-darker-theme haskell-mode
	      multiple-cursors smex typst-ts-mode yasnippet-snippets)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(add-to-list 'load-path "~/.emacs.local/")

(require 'simpc-mode)
(add-to-list 'auto-mode-alist '("\\.[hc]\\(pp\\)?\\'" . simpc-mode))

(rc/require 'smex)
(global-set-key (kbd "M-x") 'smex)
(global-set-key (kbd "C-c C-c M-x") 'execute-extended-command)

(rc/require 'multiple-cursors)

(global-set-key (kbd "C-S-c C-S-c") 'mc/edit-lines)
(global-set-key (kbd "C->") 'mc/mark-next-like-this)
(global-set-key (kbd "C-<") 'mc/mark-previous-like-this)
(global-set-key (kbd "C-c C-<") 'mc/mark-all-like-this)
(global-set-key (kbd "C-\"") 'mc/skip-to-next-like-this)
(global-set-key (kbd "C-:") 'mc/skip-to-previous-like-this)



(global-set-key (kbd "C-,") 'duplicate-line)



;; 1. 加载包
(rc/require 'typst-ts-mode)

;; 2. 关联文件后缀
(add-to-list 'auto-mode-alist '("\\.typ\\'" . typst-ts-mode))

;; 3. 具体配置
(with-eval-after-load 'typst-ts-mode
  ;; 编译时自动打开 PDF (可选)
  (setq typst-ts-mode-watch-options "--open")
  
  ;; 如果你使用 Eglot (LSP)，需要关联 LSP 服务端
  ;; 确保你已经安装了 'tinymist' 或 'typst-lsp' 命令行工具
  (with-eval-after-load 'eglot
    (add-to-list 'eglot-server-programs
                 '(typst-ts-mode . ("tinymist")))))

;; 4. 自动启动 LSP (可选)
(add-hook 'typst-ts-mode-hook 'eglot-ensure)


;; 1. 加载包
(rc/require 'markdown-mode)

;; 2. 关联文件后缀 (如果在 rc/require 中没做的话)
(add-to-list 'auto-mode-alist '("README\\.md\\'" . gfm-mode))
(add-to-list 'auto-mode-alist '("\\.md\\'" . markdown-mode))
(add-to-list 'auto-mode-alist '("\\.markdown\\'" . markdown-mode))

;; 3. 具体配置 (延迟加载，确保 markdown-mode 加载后才执行)
(with-eval-after-load 'markdown-mode
  ;; 设置编译命令 (可选 pandoc 或 multimarkdown)
  (setq markdown-command "multimarkdown")
  
  ;; 快捷键绑定
  (define-key markdown-mode-map (kbd "C-c p") 'markdown-preview)
  (define-key markdown-mode-map (kbd "C-c C-e") 'markdown-do))

(use-package dap-mode
  :ensure t
  :config
  (dap-mode 1)
  (dap-ui-mode 1) ;; 启用 UI 界面
  (dap-tooltip-mode 1) ;; 启用鼠标悬停提示
  (require 'dap-gdb-lldb)) ;; 加载 C/C++ 支持

(use-package typst-ts-mode
  :ensure t
  :mode ("\\.typ\\'" . typst-ts-mode)
  :custom
  (typst-ts-mode-watch-options "--open"))

;; 告诉 Emacs typst 的 tree-sitter 语法仓库地址
(with-eval-after-load 'treesit
  (add-to-list 'treesit-language-source-alist
               '(typst "https://github.com/uben0/tree-sitter-typst")))

;; doom/packages.el
;; typst: https://codeberg.org/meow_king/typst-ts-mode/wiki/Installation.md
(package! typst-ts-mode :recipe (:host codeberg :repo "meow_king/typst-ts-mode"))


;; save on focus lost
;; https://stackoverflow.com/q/1230245
(add-hook 'focus-out-hook (lambda () (interactive) (save-some-buffers t)))

(define-key evil-normal-state-map (kbd "<escape>") (lambda () (interactive) (save-some-buffers t)))

