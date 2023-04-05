// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/texttagtable.hxx>
#include <libmm/gtk/texttagtable_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/texttag.hxx>

static auto
SignalProxy_ForEach_gtk_callback (GtkTextTag* texttag, gpointer data) -> void
{
  auto the_slot = static_cast<gtk::TextTagTable::SlotForEach*> (data);
  if (the_slot)
  {
    (*the_slot) (glib::wrap (texttag, true));
  }
}

namespace gtk
{

  auto
  TextTagTable::foreach (const SlotForEach& slot) -> void
  {
    gtk_text_tag_table_foreach (gobj (),
                                &SignalProxy_ForEach_gtk_callback,
                                (gpointer) &slot);
  }

} // namespace gtk

namespace
{

  static auto
  TextTagTable_signal_tag_changed_callback (GtkTextTagTable* self,
                                            GtkTextTag* p0,
                                            gboolean p1,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<TextTag>&, bool)>;

    auto obj = dynamic_cast<TextTagTable*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TextTagTable_signal_tag_changed_info = {
      "tag_changed",
      (GCallback) &TextTagTable_signal_tag_changed_callback,
      (GCallback) &TextTagTable_signal_tag_changed_callback};

  static auto
  TextTagTable_signal_tag_added_callback (GtkTextTagTable* self,
                                          GtkTextTag* p0,
                                          void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<TextTag>&)>;

    auto obj = dynamic_cast<TextTagTable*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TextTagTable_signal_tag_added_info = {
      "tag_added",
      (GCallback) &TextTagTable_signal_tag_added_callback,
      (GCallback) &TextTagTable_signal_tag_added_callback};

  static auto
  TextTagTable_signal_tag_removed_callback (GtkTextTagTable* self,
                                            GtkTextTag* p0,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<TextTag>&)>;

    auto obj = dynamic_cast<TextTagTable*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TextTagTable_signal_tag_removed_info = {
      "tag_removed",
      (GCallback) &TextTagTable_signal_tag_removed_callback,
      (GCallback) &TextTagTable_signal_tag_removed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkTextTagTable* object, bool take_copy) -> glib::RefPtr<gtk::TextTagTable>
  {
    return glib::make_refptr_for_instance<gtk::TextTagTable> (
        dynamic_cast<gtk::TextTagTable*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TextTagTable_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextTagTable_Class::class_init_function;

      register_derived_type (gtk_text_tag_table_get_type ());

      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TextTagTable_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TextTagTable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TextTagTable ((GtkTextTagTable*) object);
  }

  auto
  TextTagTable::gobj_copy () -> GtkTextTagTable*
  {
    reference ();
    return gobj ();
  }

  TextTagTable::TextTagTable (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TextTagTable::TextTagTable (GtkTextTagTable* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TextTagTable::TextTagTable (TextTagTable&& src) noexcept
    : glib::Object (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  TextTagTable::operator= (TextTagTable&& src) noexcept -> TextTagTable&
  {
    glib::Object::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  TextTagTable::~TextTagTable () noexcept {}

  TextTagTable::CppClassType TextTagTable::texttagtable_class_;

  auto
  TextTagTable::get_type () -> GType
  {
    return texttagtable_class_.init ().get_type ();
  }

  auto
  TextTagTable::get_base_type () -> GType
  {
    return gtk_text_tag_table_get_type ();
  }

  TextTagTable::TextTagTable ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (texttagtable_class_.init ()))
  {
  }

  auto
  TextTagTable::create () -> glib::RefPtr<TextTagTable>
  {
    return glib::make_refptr_for_instance<TextTagTable> (new TextTagTable ());
  }

  auto
  TextTagTable::add (const glib::RefPtr<TextTag>& tag) -> bool
  {
    return gtk_text_tag_table_add (gobj (), glib::unwrap (tag));
  }

  auto
  TextTagTable::remove (const glib::RefPtr<TextTag>& tag) -> void
  {
    gtk_text_tag_table_remove (gobj (), glib::unwrap (tag));
  }

  auto
  TextTagTable::lookup (const glib::ustring& name) -> glib::RefPtr<TextTag>
  {
    auto retvalue =
        glib::wrap (gtk_text_tag_table_lookup (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextTagTable::lookup (const glib::ustring& name) const -> glib::RefPtr<const TextTag>
  {
    return const_cast<TextTagTable*> (this)->lookup (name);
  }

  auto
  TextTagTable::get_size () const -> int
  {
    return gtk_text_tag_table_get_size (const_cast<GtkTextTagTable*> (gobj ()));
  }

  auto
  TextTagTable::signal_tag_changed () -> glib::SignalProxy<void (const glib::RefPtr<TextTag>&, bool)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<TextTag>&, bool)> (
        this,
        &TextTagTable_signal_tag_changed_info);
  }

  auto
  TextTagTable::signal_tag_added () -> glib::SignalProxy<void (const glib::RefPtr<TextTag>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<TextTag>&)> (
        this,
        &TextTagTable_signal_tag_added_info);
  }

  auto
  TextTagTable::signal_tag_removed () -> glib::SignalProxy<void (const glib::RefPtr<TextTag>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<TextTag>&)> (
        this,
        &TextTagTable_signal_tag_removed_info);
  }

} // namespace gtk
