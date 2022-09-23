;;
;;  french.nsh
;;
;;  French language strings for the Windows gtkmm NSIS installer.
;;  Windows Code page: 1252
;;
;;  Author: Eric Boumaour <zongo@nekeme.net>, 2003.
;;

LangString MISC_ADMIN_REQUIRED          ${LANG_FRENCH} \
  "Des droits administrateur sont n�cessaires pour d�sinstaller${PRODUCT_NAME}. L'installation va s'arr�ter maintenant..."
LangString MISC_INSTALL_OPTION          ${LANG_FRENCH} "Option d'installation"
LangString MISC_UNINSTALL_CONTEXT       ${LANG_FRENCH} \
  "${PRODUCT_NAME} peut �tre install� pour tous les utilisateurs ou uniquement l'utilisateur actuel."
LangString MISC_ANSWER_SYSTEM           ${LANG_FRENCH} \
  "Veuillez r�pondre aux questions suivantes relatives � votre syst�me."


LangString GTKMM_PREVIOUS_VERSION       ${LANG_FRENCH} \
"Une version pr�c�dente de ${PRODUCT_NAME} ($R1) a �t� d�tect�e. Etes-vous d'accord de la d�sinstaller maintenant ? $\n$\nCliquer sur `Oui` pour supprimer \
  la version pr�c�dente, `Non` pour l'�craser, ou `Annuler` pour annuler cette mise � jour."
LangString GTKMM_PREVIOUS_ERROR         ${LANG_FRENCH} \
  "Une erreur s'est produite ou une version pr�c�dente de ${PRODUCT_NAME} ($R1) n'a pas �t� correctement d�sinstall�e. \
   L'installation va s'arr�ter maintenant."
LangString GTKMM_NEWER                  ${LANG_FRENCH} \
"${PRODUCT_NAME} ($R1) est d�j� install� sur votre syst�me, et est plus r�cent que cette distribution (${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER})."
   
LangString GTKMM_ADD_PATH               ${LANG_FRENCH} \
"Ajouter le repertoire racine de gtkmm � la variable PATH"

;; TODO: This needs to be translated!
LangString GTKMM_DIRECTORYPAGE_HINT     ${LANG_FRENCH} \
"Setup will install ${PRODUCT_FULLNAME} ${PRODUCT_VERSION} in the following folder. To install in a different folder, click Browse and select another folder. Click Next to continue.$\r$\n$\r$\nIf you intend to use MinGW, then it is not recommended to use a path that has space characters in it because this will break pkg-config."

LangString GTKMM_RIGHTS_INSTALL         ${LANG_FRENCH} \
"Installer pour"
LangString GTKMM_RIGHTS_ANYONE          ${LANG_FRENCH} \
"Tous les utilisateurs de cet ordinateur"
LangString GTKMM_RIGHTS_CURRENT         ${LANG_FRENCH} \
"Uniquement l'utilisateur actuel"
