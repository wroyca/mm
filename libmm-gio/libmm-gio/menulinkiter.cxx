

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/menulinkiter.hxx>
#include <libmm-gio/menulinkiter_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/menumodel.hxx>

namespace Gio
{

  auto
  MenuLinkIter::get_next (Glib::ustring& out_link,
                          Glib::RefPtr<MenuModel>& value) -> bool
  {
    const char* g_out_link = nullptr;
    GMenuModel* g_value = nullptr;

    const bool result =
        g_menu_link_iter_get_next (gobj (), &g_out_link, &g_value);
    out_link = g_out_link;
    value = Glib::wrap (g_value);

    return result;
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GMenuLinkIter* object, const bool take_copy) -> RefPtr<Gio::MenuLinkIter>
  {
    return Glib::make_refptr_for_instance<Gio::MenuLinkIter> (
        dynamic_cast<Gio::MenuLinkIter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  MenuLinkIter_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuLinkIter_Class::class_init_function;

      register_derived_type (g_menu_link_iter_get_type ());
    }

    return *this;
  }

  auto
  MenuLinkIter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuLinkIter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MenuLinkIter ((GMenuLinkIter*) object);
  }

  auto
  MenuLinkIter::gobj_copy () -> GMenuLinkIter*
  {
    reference ();
    return gobj ();
  }

  MenuLinkIter::MenuLinkIter (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  MenuLinkIter::MenuLinkIter (GMenuLinkIter* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MenuLinkIter::MenuLinkIter (MenuLinkIter&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  MenuLinkIter::operator= (MenuLinkIter&& src) noexcept -> MenuLinkIter&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  MenuLinkIter::~MenuLinkIter () noexcept = default;

  MenuLinkIter::CppClassType MenuLinkIter::menulinkiter_class_;

  auto
  MenuLinkIter::get_type () -> GType
  {
    return menulinkiter_class_.init ().get_type ();
  }

  auto
  MenuLinkIter::get_base_type () -> GType
  {
    return g_menu_link_iter_get_type ();
  }

  MenuLinkIter::MenuLinkIter ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (menulinkiter_class_.init ()))
  {
  }

  auto
  MenuLinkIter::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_menu_link_iter_get_name (const_cast<GMenuLinkIter*> (gobj ())));
  }

  auto
  MenuLinkIter::get_value () -> Glib::RefPtr<MenuModel>
  {
    return Glib::wrap (g_menu_link_iter_get_value (gobj ()));
  }

  auto
  MenuLinkIter::get_value () const -> Glib::RefPtr<const MenuModel>
  {
    return const_cast<MenuLinkIter*> (this)->get_value ();
  }

  auto
  MenuLinkIter::next () -> bool
  {
    return g_menu_link_iter_next (gobj ());
  }

} // namespace Gio
