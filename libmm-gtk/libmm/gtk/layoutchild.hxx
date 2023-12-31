// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LAYOUTCHILD_H
#define _GTKMM_LAYOUTCHILD_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLayoutChild = struct _GtkLayoutChild;
using GtkLayoutChildClass = struct _GtkLayoutChildClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT LayoutChild_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT LayoutManager;
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT LayoutChild : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = LayoutChild;
    using CppClassType = LayoutChild_Class;
    using BaseObjectType = GtkLayoutChild;
    using BaseClassType = GtkLayoutChildClass;

    LayoutChild (const LayoutChild&) = delete;
    auto
    operator= (const LayoutChild&) -> LayoutChild& = delete;

  private:
    friend class LayoutChild_Class;
    static CppClassType layoutchild_class_;

  protected:
    explicit LayoutChild (const glib::ConstructParams& construct_params);
    explicit LayoutChild (GtkLayoutChild* castitem);

#endif

  public:
    LayoutChild (LayoutChild&& src) noexcept;
    auto
    operator= (LayoutChild&& src) noexcept -> LayoutChild&;

    ~LayoutChild () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLayoutChild*
    {
      return reinterpret_cast<GtkLayoutChild*> (gobject_);
    }

    auto
    gobj () const -> const GtkLayoutChild*
    {
      return reinterpret_cast<GtkLayoutChild*> (gobject_);
    }

    auto
    gobj_copy () -> GtkLayoutChild*;

  private:
  protected:
    LayoutChild ();

  public:
    auto
    get_layout_manager () -> glib::RefPtr<LayoutManager>;

    auto
    get_layout_manager () const -> glib::RefPtr<const LayoutManager>;

    auto
    get_child_widget () -> Widget*;

    auto
    get_child_widget () const -> const Widget*;

    auto
    property_layout_manager () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>>;

    auto
    property_child_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkLayoutChild* object, bool take_copy = false) -> glib::RefPtr<gtk::LayoutChild>;
} // namespace glib

#endif
