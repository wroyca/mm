// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BOXLAYOUT_H
#define _GTKMM_BOXLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/layoutmanager.hxx>
#include <libmm/gtk/orientable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT BoxLayout_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT BoxLayout : public LayoutManager,
                              public Orientable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BoxLayout;
    using CppClassType = BoxLayout_Class;
    using BaseObjectType = GtkBoxLayout;
    using BaseClassType = GtkBoxLayoutClass;

    BoxLayout (const BoxLayout&) = delete;
    auto
    operator= (const BoxLayout&) -> BoxLayout& = delete;

  private:
    friend class BoxLayout_Class;
    static CppClassType boxlayout_class_;

  protected:
    explicit BoxLayout (const glib::ConstructParams& construct_params);
    explicit BoxLayout (GtkBoxLayout* castitem);

#endif

  public:
    BoxLayout (BoxLayout&& src) noexcept;
    auto
    operator= (BoxLayout&& src) noexcept -> BoxLayout&;

    ~BoxLayout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBoxLayout*
    {
      return reinterpret_cast<GtkBoxLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkBoxLayout*
    {
      return reinterpret_cast<GtkBoxLayout*> (gobject_);
    }

    auto
    gobj_copy () -> GtkBoxLayout*;

  private:
  protected:
    explicit BoxLayout (Orientation orientation = Orientation::HORIZONTAL);

  public:
    static auto
    create (Orientation orientation = Orientation::HORIZONTAL)
        -> glib::RefPtr<BoxLayout>;

    auto
    set_homogeneous (bool homogeneous = true) -> void;

    auto
    get_homogeneous () const -> bool;

    auto
    set_spacing (guint spacing) -> void;

    auto
    get_spacing () const -> guint;

    auto
    set_baseline_position (BaselinePosition position) -> void;

    auto
    get_baseline_position () const -> BaselinePosition;

    auto
    property_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_spacing () -> glib::PropertyProxy<int>;

    auto
    property_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_baseline_position () -> glib::PropertyProxy<BaselinePosition>;

    auto
    property_baseline_position () const
        -> glib::PropertyProxy_ReadOnly<BaselinePosition>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBoxLayout* object, bool take_copy = false) -> glib::RefPtr<gtk::BoxLayout>;
} // namespace glib

#endif
