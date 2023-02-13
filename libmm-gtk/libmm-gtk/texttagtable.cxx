


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/texttagtable.hxx>
#include <libmm-gtk/texttagtable_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gtk/texttag.hxx>
#include <gtk/gtk.h>


static auto SignalProxy_ForEach_gtk_callback (GtkTextTag *texttag, const gpointer data) -> void
{
  const auto the_slot = static_cast<Gtk::TextTagTable::SlotForEach*>(data);
  if(the_slot)
  {
    //Use Slot::operator():
    (*the_slot)(Glib::wrap(texttag, true)); //true = take_copy.
  }
}

namespace Gtk
{

auto TextTagTable::foreach (const SlotForEach &slot) -> void
{
  //The slot doesn't need to exist for longer than the function call.
  gtk_text_tag_table_foreach(gobj(),  &SignalProxy_ForEach_gtk_callback, (gpointer)&slot);
}


} //namespace Gtk


namespace
{


auto TextTagTable_signal_tag_changed_callback (
  GtkTextTagTable *self, GtkTextTag *p0, const gboolean p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<TextTag>&, bool)>;

  const auto obj = dynamic_cast<TextTagTable*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TextTagTable_signal_tag_changed_info =
{
  "tag_changed",
  (GCallback) &TextTagTable_signal_tag_changed_callback,
  (GCallback) &TextTagTable_signal_tag_changed_callback
};


auto TextTagTable_signal_tag_added_callback (
  GtkTextTagTable *self, GtkTextTag *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<TextTag>&)>;

  const auto obj = dynamic_cast<TextTagTable*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TextTagTable_signal_tag_added_info =
{
  "tag_added",
  (GCallback) &TextTagTable_signal_tag_added_callback,
  (GCallback) &TextTagTable_signal_tag_added_callback
};


auto TextTagTable_signal_tag_removed_callback (
  GtkTextTagTable *self, GtkTextTag *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<TextTag>&)>;

  const auto obj = dynamic_cast<TextTagTable*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TextTagTable_signal_tag_removed_info =
{
  "tag_removed",
  (GCallback) &TextTagTable_signal_tag_removed_callback,
  (GCallback) &TextTagTable_signal_tag_removed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkTextTagTable* object, const bool take_copy) -> RefPtr<Gtk::TextTagTable>
{
  return Glib::make_refptr_for_instance<Gtk::TextTagTable>( dynamic_cast<Gtk::TextTagTable*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TextTagTable_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TextTagTable_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_text_tag_table_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Buildable::add_interface(get_type());

  }

  return *this;
}


auto TextTagTable_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TextTagTable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TextTagTable((GtkTextTagTable*)object);
}


/* The implementation: */

auto TextTagTable::gobj_copy() -> GtkTextTagTable*
{
  reference();
  return gobj();
}

TextTagTable::TextTagTable(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TextTagTable::TextTagTable(GtkTextTagTable* castitem)
: Object((GObject*)castitem)
{}


TextTagTable::TextTagTable(TextTagTable&& src) noexcept
: Object(std::move(src))
  , Buildable(std::move(src))
{}

auto TextTagTable::operator=(TextTagTable&& src) noexcept -> TextTagTable&
{
  Object::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


TextTagTable::~TextTagTable() noexcept = default;

TextTagTable::CppClassType TextTagTable::texttagtable_class_; // initialize static member

auto TextTagTable::get_type() -> GType
{
  return texttagtable_class_.init().get_type();
}


auto TextTagTable::get_base_type() -> GType
{
  return gtk_text_tag_table_get_type();
}


TextTagTable::TextTagTable()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(texttagtable_class_.init()))
{


}

auto TextTagTable::create() -> Glib::RefPtr<TextTagTable>
{
  return Glib::make_refptr_for_instance<TextTagTable>( new TextTagTable() );
}

auto TextTagTable::add(const Glib::RefPtr<TextTag>& tag) -> bool
{
  return gtk_text_tag_table_add(gobj(), Glib::unwrap(tag));
}

auto TextTagTable::remove (const Glib::RefPtr <TextTag> &tag) -> void
{
  gtk_text_tag_table_remove(gobj(), Glib::unwrap(tag));
}

auto TextTagTable::lookup(const Glib::ustring& name) -> Glib::RefPtr<TextTag>
{
  auto retvalue = Glib::wrap(gtk_text_tag_table_lookup(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextTagTable::lookup(const Glib::ustring& name) const -> Glib::RefPtr<const TextTag>
{
  return const_cast<TextTagTable*>(this)->lookup(name);
}

auto TextTagTable::get_size() const -> int
{
  return gtk_text_tag_table_get_size(const_cast<GtkTextTagTable*>(gobj()));
}


auto TextTagTable::signal_tag_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&, bool)>
{
  return {this, &TextTagTable_signal_tag_changed_info};
}


auto TextTagTable::signal_tag_added() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&)>
{
  return {this, &TextTagTable_signal_tag_added_info};
}


auto TextTagTable::signal_tag_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&)>
{
  return {this, &TextTagTable_signal_tag_removed_info};
}


} // namespace Gtk


