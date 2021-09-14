# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:26 CST. 

if [ -z "${QT_GRAPHICSSYSTEM_CHECKED}" -a -z "${QT_GRAPHICSSYSTEM}" ] ; then
  QT_GRAPHICSSYSTEM_CHECKED=1
  export QT_GRAPHICSSYSTEM_CHECKED

  # workarond cirrus/qt bug, http://bugzilla.redhat.com/810161
  if ( /usr/sbin/lspci 2>/dev/null | grep -qi "VGA compatible controller: Cirrus Logic GD 5446" ) ; then
    QT_GRAPHICSSYSTEM=native
    export QT_GRAPHICSSYSTEM
  fi
fi

