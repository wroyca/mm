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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT NotebookPage_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT NotebookPage : public glib::Object
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
    explicit NotebookPage (const glib::ConstructParams& construct_params);
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
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_tab () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_menu () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_tab_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_tab_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_menu_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_menu_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_position () -> glib::PropertyProxy<int>;

    auto
    property_position () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tab_expand () -> glib::PropertyProxy<bool>;

    auto
    property_tab_expand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tab_fill () -> glib::PropertyProxy<bool>;

    auto
    property_tab_fill () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reorderable () -> glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_detachable () -> glib::PropertyProxy<bool>;

    auto
    property_detachable () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNotebookPage* object, bool take_copy = false) -> glib::RefPtr<gtk::NotebookPage>;
} // namespace glib

#endif
