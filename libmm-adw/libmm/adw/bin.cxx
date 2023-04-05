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
  wrap (AdwBin* object, bool take_copy) -> adw::Bin*
  {
    return dynamic_cast<adw::Bin*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Bin_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Bin_Class::class_init_function;

      register_derived_type (adw_bin_get_type ());
    }

    return *this;
  }

  auto
  Bin_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Bin_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Bin ((AdwBin*) (o)));
  }

  Bin::Bin (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Bin::Bin (AdwBin* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Bin::Bin (Bin&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Bin::operator= (Bin&& src) noexcept -> Bin&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Bin::~Bin () noexcept
  {
    destroy_ ();
  }

  Bin::CppClassType Bin::bin_class_;

  auto
  Bin::get_type () -> GType
  {
    return bin_class_.init ().get_type ();
  }

  auto
  Bin::get_base_type () -> GType
  {
    return adw_bin_get_type ();
  }

  Bin::Bin ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (bin_class_.init ()))
  {
  }

  auto
  Bin::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_bin_get_child (const_cast<AdwBin*> (gobj ())));
  }

  auto
  Bin::set_child (gtk::Widget* widget) -> void
  {
    adw_bin_set_child (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  Bin::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  Bin::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

} // namespace adw
