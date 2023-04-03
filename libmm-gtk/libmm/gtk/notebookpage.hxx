// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NOTEBOOKPAGE_H
#define _GTKMM_NOTEBOOKPAGE_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNotebookPage = struct _GtkNotebookPage;
using GtkNotebookPageClass = struct _GtkNotebookPageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT NotebookPage_Class;
}
#endif

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT NotebookPage : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NotebookPage;
    using CppClassType = NotebookPage_Class;
    using BaseObjectType = GtkNotebookPage;
    using BaseClassType = GtkNotebookPageClass;

    NotebookPage (const NotebookPage&) = delete;
    auto
    operator= (const NotebookPage&) -> NotebookPage& = delete;

  private:
    friend class NotebookPage_Class;
    static CppClassType notebookpage_class_;

  protected:
    explicit NotebookPage (const Glib::ConstructParams& construct_params);
    explicit NotebookPage (GtkNotebookPage* castitem);

#endif

  public:
    NotebookPage (NotebookPage&& src) noexcept;
    auto
    operator= (NotebookPage&& src) noexcept -> NotebookPage&;

    ~NotebookPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNotebookPage*
    {
      return reinterpret_cast<GtkNotebookPage*> (gobject_);
    }

    auto
    gobj () const -> const GtkNotebookPage*
    {
      return reinterpret_cast<GtkNotebookPage*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNotebookPage*;

  private:
  public:
    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_tab () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_menu () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_tab_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tab_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_menu_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_menu_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_position () -> Glib::PropertyProxy<int>;

    auto
    property_position () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tab_expand () -> Glib::PropertyProxy<bool>;

    auto
    property_tab_expand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tab_fill () -> Glib::PropertyProxy<bool>;

    auto
    property_tab_fill () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reorderable () -> Glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_detachable () -> Glib::PropertyProxy<bool>;

    auto
    property_detachable () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNotebookPage* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NotebookPage>;
} // namespace Glib

#endif
