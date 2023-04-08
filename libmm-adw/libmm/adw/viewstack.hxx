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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT view_stack_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT view_stack : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = view_stack;
    using CppClassType = view_stack_class;
    using BaseObjectType = AdwViewStack;
    using BaseClassType = AdwViewStackClass;
#endif

    view_stack (view_stack&& src) noexcept;
    auto
    operator= (view_stack&& src) noexcept -> view_stack&;

    view_stack (const view_stack&) = delete;
    auto
    operator= (const view_stack&) -> view_stack& = delete;

    ~view_stack () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class view_stack_class;
    static CppClassType viewstack_class_;

  protected:
    explicit view_stack (const glib::ConstructParams& construct_params);
    explicit view_stack (AdwViewStack* castitem);

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
    view_stack ();

    auto
    add (gtk::Widget* child) -> glib::RefPtr<view_stack_page>;

    auto
    add_named (gtk::Widget* child, const glib::ustring& name)
        -> glib::RefPtr<view_stack_page>;

    auto
    add_titled (gtk::Widget* child,
                const glib::ustring& name,
                const glib::ustring& title) -> glib::RefPtr<view_stack_page>;

    auto
    add_titled_with_icon (gtk::Widget* child,
                          const glib::ustring& name,
                          const glib::ustring& title,
                          const glib::ustring& icon_name)
        -> glib::RefPtr<view_stack_page>;

    auto
    get_child_by_name (const glib::ustring& name) const -> gtk::Widget*;

    auto
    get_hhomogeneous () const -> bool;

    auto
    get_page (gtk::Widget* child) const -> glib::RefPtr<view_stack_page>;

    auto
    get_pages () const -> glib::RefPtr<gtk::SelectionModel>;

    auto
    get_vhomogeneous () const -> bool;

    auto
    get_visible_child () const -> gtk::Widget*;

    auto
    get_visible_child_name () const -> glib::ustring;

    auto
    remove (gtk::Widget* widget) -> void;

    auto
    set_hhomogeneous (bool hhomogeneous) -> void;

    auto
    set_vhomogeneous (bool hhomogeneous) -> void;

    auto
    set_visible_child (gtk::Widget* child) -> void;

    auto
    set_visible_child_name (const glib::ustring& name) -> void;

    auto
    property_hhomogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_hhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>;

    auto
    property_vhomogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_vhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_visible_child () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_visible_child_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_visible_child_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewStack* object, bool take_copy = false) -> adw::view_stack*;
}

#endif
