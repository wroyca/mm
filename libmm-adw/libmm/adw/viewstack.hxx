// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSTACK_H
#define _LIBADWAITAMM_VIEWSTACK_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/viewstackpage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ViewStack_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ViewStack : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ViewStack CppObjectType;
    typedef ViewStack_Class CppClassType;
    typedef AdwViewStack BaseObjectType;
    typedef AdwViewStackClass BaseClassType;
#endif

    ViewStack (ViewStack&& src) noexcept;
    auto
    operator= (ViewStack&& src) noexcept -> ViewStack&;

    ViewStack (const ViewStack&) = delete;
    auto
    operator= (const ViewStack&) -> ViewStack& = delete;

    ~ViewStack () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ViewStack_Class;
    static CppClassType viewstack_class_;

  protected:
    explicit ViewStack (const Glib::ConstructParams& construct_params);
    explicit ViewStack (AdwViewStack* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwViewStack*
    {
      return reinterpret_cast<AdwViewStack*> (gobject_);
    }

    auto
    gobj () const -> const AdwViewStack*
    {
      return reinterpret_cast<AdwViewStack*> (gobject_);
    }

  private:
  public:
    ViewStack ();

    auto
    add (Gtk::Widget* child) -> Glib::RefPtr<ViewStackPage>;

    auto
    add_named (Gtk::Widget* child, const Glib::ustring& name)
        -> Glib::RefPtr<ViewStackPage>;

    auto
    add_titled (Gtk::Widget* child,
                const Glib::ustring& name,
                const Glib::ustring& title) -> Glib::RefPtr<ViewStackPage>;

    auto
    add_titled_with_icon (Gtk::Widget* child,
                          const Glib::ustring& name,
                          const Glib::ustring& title,
                          const Glib::ustring& icon_name)
        -> Glib::RefPtr<ViewStackPage>;

    auto
    get_child_by_name (const Glib::ustring& name) const -> Gtk::Widget*;

    auto
    get_hhomogeneous () const -> bool;

    auto
    get_page (Gtk::Widget* child) const -> Glib::RefPtr<ViewStackPage>;

    auto
    get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>;

    auto
    get_vhomogeneous () const -> bool;

    auto
    get_visible_child () const -> Gtk::Widget*;

    auto
    get_visible_child_name () const -> Glib::ustring;

    auto
    remove (Gtk::Widget* widget) -> void;

    auto
    set_hhomogeneous (bool hhomogeneous) -> void;

    auto
    set_vhomogeneous (bool hhomogeneous) -> void;

    auto
    set_visible_child (Gtk::Widget* child) -> void;

    auto
    set_visible_child_name (const Glib::ustring& name) -> void;

    auto
    property_hhomogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_hhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>;

    auto
    property_vhomogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_vhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_visible_child () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_visible_child_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_visible_child_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwViewStack* object, bool take_copy = false) -> Adw::ViewStack*;
}

#endif
