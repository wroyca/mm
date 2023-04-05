// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MEDIAFILE_P_H
#define _GTKMM_MEDIAFILE_P_H

#include <libmm/gtk/mediastream_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MediaFile_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MediaFile;
    using BaseObjectType = GtkMediaFile;
    using BaseClassType = GtkMediaFileClass;
    using CppClassParent = gtk::MediaStream_Class;
    using BaseClassParent = GtkMediaStreamClass;

    friend class MediaFile;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    open_vfunc_callback (GtkMediaFile* self) -> void;
    static auto
    close_vfunc_callback (GtkMediaFile* self) -> void;
  };

} // namespace gtk

#endif
