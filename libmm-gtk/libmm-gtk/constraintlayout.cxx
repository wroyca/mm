

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/constraintlayout.hxx>
#include <libmm-gtk/constraintlayout_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  ConstraintLayout::add_constraint (const Glib::RefPtr<Constraint>& constraint) -> void
  {
    if (constraint)
      constraint->reference ();
    gtk_constraint_layout_add_constraint (gobj (), Glib::unwrap (constraint));
  }

  auto
  ConstraintLayout::add_guide (const Glib::RefPtr<ConstraintGuide>& guide) -> void
  {
    if (guide)
      guide->reference ();
    gtk_constraint_layout_add_guide (gobj (), Glib::unwrap (guide));
  }

  auto
  ConstraintLayout::add_constraints_from_description (
      const std::vector<Glib::ustring>& lines,
      const int hspacing,
      const int vspacing,
      const VFLmap& views) -> std::vector<Glib::RefPtr<Constraint>>
  {
    GHashTable* hash_table_views = g_hash_table_new (g_str_hash, g_str_equal);
    for (const auto& it : views)
      g_hash_table_insert (hash_table_views,
                           const_cast<char*> (it.first.c_str ()),
                           it.second->gobj ());

    GError* gerror = nullptr;
    GList* constraints =
        gtk_constraint_layout_add_constraints_from_descriptionv (
            gobj (),
            Glib::ArrayHandler<Glib::ustring>::vector_to_array (lines).data (),
            lines.size (),
            hspacing,
            vspacing,
            hash_table_views,
            &gerror);

    g_hash_table_unref (hash_table_views);

    if (gerror)
    {
      g_list_free (constraints);
      Glib::Error::throw_exception (gerror);
    }

    return Glib::ListHandler<Glib::RefPtr<Constraint>>::list_to_vector (
        constraints,
        Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Gtk

namespace
{
}

Gtk::ConstraintVflParserError::ConstraintVflParserError (
    const Code error_code,
    const Glib::ustring& error_message)
  : Error (GTK_CONSTRAINT_VFL_PARSER_ERROR, error_code, error_message)
{
}

Gtk::ConstraintVflParserError::ConstraintVflParserError (GError* gobject)
  : Error (gobject)
{
}

auto
Gtk::ConstraintVflParserError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gtk::ConstraintVflParserError::throw_func (GError* gobject) -> void
{
  throw ConstraintVflParserError (gobject);
}

auto
Glib::Value<Gtk::ConstraintVflParserError::Code>::value_type () -> GType
{
  return gtk_constraint_vfl_parser_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkConstraintLayout* object, const bool take_copy) -> RefPtr<Gtk::ConstraintLayout>
  {
    return Glib::make_refptr_for_instance<Gtk::ConstraintLayout> (
        dynamic_cast<Gtk::ConstraintLayout*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ConstraintLayout_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConstraintLayout_Class::class_init_function;

      gtype_ = gtk_constraint_layout_get_type ();
    }

    return *this;
  }

  auto
  ConstraintLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ConstraintLayout_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ConstraintLayout ((GtkConstraintLayout*) object);
  }

  auto
  ConstraintLayout::gobj_copy () -> GtkConstraintLayout*
  {
    reference ();
    return gobj ();
  }

  ConstraintLayout::ConstraintLayout (
      const Glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  ConstraintLayout::ConstraintLayout (GtkConstraintLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) castitem)
  {
  }

  ConstraintLayout::ConstraintLayout (ConstraintLayout&& src) noexcept
    : LayoutManager (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  ConstraintLayout::operator= (ConstraintLayout&& src) noexcept -> ConstraintLayout&
  {
    LayoutManager::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  ConstraintLayout::~ConstraintLayout () noexcept = default;

  ConstraintLayout::CppClassType ConstraintLayout::constraintlayout_class_;

  auto
  ConstraintLayout::get_type () -> GType
  {
    return constraintlayout_class_.init ().get_type ();
  }

  auto
  ConstraintLayout::get_base_type () -> GType
  {
    return gtk_constraint_layout_get_type ();
  }

  ConstraintLayout::ConstraintLayout ()
    : ObjectBase (nullptr),
      LayoutManager (Glib::ConstructParams (constraintlayout_class_.init ()))
  {
  }

  auto
  ConstraintLayout::create () -> Glib::RefPtr<ConstraintLayout>
  {
    return Glib::make_refptr_for_instance<ConstraintLayout> (
        new ConstraintLayout ());
  }

  auto
  ConstraintLayout::remove_constraint (
      const Glib::RefPtr<Constraint>& constraint) -> void
  {
    gtk_constraint_layout_remove_constraint (gobj (),
                                             Glib::unwrap (constraint));
  }

  auto
  ConstraintLayout::remove_all_constraints () -> void
  {
    gtk_constraint_layout_remove_all_constraints (gobj ());
  }

  auto
  ConstraintLayout::remove_guide (const Glib::RefPtr<ConstraintGuide>& guide) -> void
  {
    gtk_constraint_layout_remove_guide (gobj (), Glib::unwrap (guide));
  }

  auto
  ConstraintLayout::observe_constraints () -> Glib::RefPtr<Gio::ListModel>
  {
    return Glib::wrap (gtk_constraint_layout_observe_constraints (gobj ()));
  }

  auto
  ConstraintLayout::observe_constraints () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<ConstraintLayout*> (this)->observe_constraints ();
  }

  auto
  ConstraintLayout::observe_guides () -> Glib::RefPtr<Gio::ListModel>
  {
    return Glib::wrap (gtk_constraint_layout_observe_guides (gobj ()));
  }

  auto
  ConstraintLayout::observe_guides () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<ConstraintLayout*> (this)->observe_guides ();
  }

} // namespace Gtk
