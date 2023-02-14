

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/scrollbar.hxx>
#include <libmm-gtk/scrollbar_p.hxx>

#include <libmm-gtk/adjustment.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  Scrollbar::Scrollbar (const Glib::RefPtr<Adjustment>& adjustment,
                        const Orientation orientation)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (scrollbar_class_.init (),
                                     "adjustment",
                                     Glib::unwrap (adjustment),
                                     "orientation",
                                     orientation,
                                     nullptr))
  {
  }

  auto
  Scrollbar::unset_adjustment () -> void
  {
    gtk_scrollbar_set_adjustment (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkScrollbar* object, const bool take_copy) -> Gtk::Scrollbar*
  {
    return dynamic_cast<Gtk::Scrollbar*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Scrollbar_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Scrollbar_Class::class_init_function;

      register_derived_type (gtk_scrollbar_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Scrollbar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Scrollbar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Scrollbar ((GtkScrollbar*) o));
  }

  Scrollbar::Scrollbar (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Scrollbar::Scrollbar (GtkScrollbar* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Scrollbar::Scrollbar (Scrollbar&& src) noexcept
    : Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Scrollbar::operator= (Scrollbar&& src) noexcept -> Scrollbar&
  {
    Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Scrollbar::~Scrollbar () noexcept
  {
    destroy_ ();
  }

  Scrollbar::CppClassType Scrollbar::scrollbar_class_;

  auto
  Scrollbar::get_type () -> GType
  {
    return scrollbar_class_.init ().get_type ();
  }

  auto
  Scrollbar::get_base_type () -> GType
  {
    return gtk_scrollbar_get_type ();
  }

  Scrollbar::Scrollbar ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (scrollbar_class_.init ()))
  {
  }

  auto
  Scrollbar::set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_scrollbar_set_adjustment (gobj (), Glib::unwrap (adjustment));
  }

  auto
  Scrollbar::get_adjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_scrollbar_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollbar::get_adjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<Scrollbar*> (this)->get_adjustment ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scrollbar::property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return {this, "adjustment"};
  }

  auto
  Scrollbar::property_adjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return {this, "adjustment"};
  }

} // namespace Gtk
