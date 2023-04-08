// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/bin.hxx>
#include <libmm/adw/bin_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwBin* object, bool take_copy) -> adw::bin*
  {
    return dynamic_cast<adw::bin*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  bin_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &bin_class::class_init_function;

      register_derived_type (adw_bin_get_type ());
    }

    return *this;
  }

  auto
  bin_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  bin_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new bin ((AdwBin*) (o)));
  }

  bin::bin (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  bin::bin (AdwBin* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  bin::bin (bin&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  bin::operator= (bin&& src) noexcept -> bin&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  bin::~bin () noexcept
  {
    destroy_ ();
  }

  bin::CppClassType bin::bin_class_;

  auto
  bin::get_type () -> GType
  {
    return bin_class_.init ().get_type ();
  }

  auto
  bin::get_base_type () -> GType
  {
    return adw_bin_get_type ();
  }

  bin::bin ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (bin_class_.init ()))
  {
  }

  auto
  bin::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_bin_get_child (const_cast<AdwBin*> (gobj ())));
  }

  auto
  bin::set_child (gtk::Widget* widget) -> void
  {
    adw_bin_set_child (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  bin::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  bin::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

} // namespace adw
