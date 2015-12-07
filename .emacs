;;time
    (display-time)
    (setq display-time-24hr-format t)
    (setq display-time-day-and-date t)
    (setq display-time-interval 10)
    
;;change the line automatically
(setq default-fill-column 80)

;;compile and run
(defun comp_run ()
(interactive)
(save-some-buffers t)
(setq file_name (buffer-file-name(current-buffer)))
(setq file_type  (substring file_name (string-match "[.][A-Za-z]*$" file_name) (length file_name)))
(setq file_name_noext (substring file_name 0 (string-match "[.][A-Za-z]*$" file_name)))
(cond
 ((string-equal file_type ".cpp") (compile (concat "g++ \"" file_name "\" -o \"" file_name_noext "\" -lm -DQWERTIER && \"" file_name_noext ".exe\"")))
 ((string-equal file_type ".py") (compile (concat "python \"" file_name "\"")))
)
)
(global-set-key [(f9)] 'comp_run)

;;maximize the window
(run-with-idle-timer 0.5 nil 'w32-send-sys-command 61488)  

(require 'autoinsert)
(auto-insert-mode)
(setq auto-insert-directory "~/.templates/")
(setq auto-insert-query nil)   
(define-auto-insert "\.cpp" "TEMPLATE.cpp.tpl")

;;indent
(setq-default indent-tabs-mode  nil)
(setq indent-tabs-mode nil)
(require 'cc-mode)


(add-to-list 'custom-theme-load-path "~/.emacs.d/themes/") 

;;time
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-safe-themes (quote ("c3c0a3702e1d6c0373a0f6a557788dfd49ec9e66e753fb24493579859c8e95ab" default)))
 '(display-time-mode t))

(load-theme 'molokai t)

(global-linum-mode 1) ; always show line numbers                              
(setq linum-format "%d")  ;set format  

(add-hook 'LaTeX-mode-hook
          #'(lambda ()
              (add-to-list 'TeX-command-list '("XeLaTeX" "%`xelatex%(mode)%' %t" TeX-run-TeX nil t))
              (setq TeX-command-default "XeLaTeX") ;; …Ë∂®ƒ¨»œ±‡“Î√¸¡ÓŒ™XeLaTeX
))

;;English Font
(set-face-attribute
'default nil :font "Monaco 10")
;;Chinese Font
(dolist (charset '(kana han symbol cjk-misc bopomofo))
(set-fontset-font (frame-parameter nil 'font)
charset
(font-spec :family "Œ¢»Ì—≈∫⁄" :size 14)))
