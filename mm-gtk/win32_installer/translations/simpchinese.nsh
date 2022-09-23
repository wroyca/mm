;;
;;  simpchinese.nsh
;;
;;  Simplified Chinese language strings for the Windows gtkmm NSIS installer.
;;  Windows Code page: 936
;;
;;  Author: Tao Wang <dancefire@gmail.com>, 2009
;;

LangString MISC_ADMIN_REQUIRED          ${LANG_SIMPCHINESE} \
  "��Ҫ����ԱȨ����ж�� ${PRODUCT_NAME}. ���������˳���װ���..."
LangString MISC_INSTALL_OPTION          ${LANG_SIMPCHINESE} "��װѡ��"
LangString MISC_UNINSTALL_CONTEXT       ${LANG_SIMPCHINESE} \
  "������ѡ��Ϊ������̨��������û���ֻ�����Լ�����װ ${PRODUCT_NAME}��"
LangString MISC_ANSWER_SYSTEM           ${LANG_SIMPCHINESE} \
  "��ش�����ϵͳ��ص����⡣"

LangString GTKMM_PREVIOUS_VERSION       ${LANG_SIMPCHINESE} \
"��⵽�����ڰ汾 ${PRODUCT_NAME} ($R1). ��������ж����ô�� \
$\n$\n��ж�����ڰ汾���� '��'���뽫�串������ '��'����ȡ������������� 'ȡ��'��"
LangString GTKMM_PREVIOUS_ERROR         ${LANG_SIMPCHINESE} \
'������һ��λ�ô��󣬻������ڰ汾 ${PRODUCT_NAME} ($R1) δ��ж�ء���װ�������ֹͣ��'
LangString GTKMM_ADD_PATH               ${LANG_SIMPCHINESE} \
"��� gtkmm ����Ŀ¼�� PATH ��������"
LangString GTKMM_NEWER                  ${LANG_SIMPCHINESE} \
"${PRODUCT_NAME} ($R1) �Ѿ�������ϵͳ�ϰ�װ�ˣ��������ڱ������汾(${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER})."

;; TODO: This needs to be translated!
LangString GTKMM_DIRECTORYPAGE_HINT     ${LANG_SIMPCHINESE} \
"Setup will install ${PRODUCT_FULLNAME} ${PRODUCT_VERSION} in the following folder. To install in a different folder, click Browse and select another folder. Click Next to continue.$\r$\n$\r$\nIf you intend to use MinGW, then it is not recommended to use a path that has space characters in it because this will break pkg-config."

LangString GTKMM_RIGHTS_INSTALL               ${LANG_SIMPCHINESE} \
"��װ��"
LangString GTKMM_RIGHTS_ANYONE               ${LANG_SIMPCHINESE} \
"��̨������ϵ������û�"
LangString GTKMM_RIGHTS_CURRENT               ${LANG_SIMPCHINESE} \
"ֻ����"
