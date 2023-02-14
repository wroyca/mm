

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileicon.hxx>
#include <libmm-gio/fileicon_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GFileIcon* object, const bool take_copy) -> RefPtr<Gio::FileIcon>
  {
    return Glib::make_refptr_for_instance<Gio::FileIcon> (
        dynamic_cast<Gio::FileIcon*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileIcon_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileIcon_Class::class_init_function;

      register_derived_type (g_file_icon_get_type ());

      Icon::add_interface (get_type ());
      LoadableIcon::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileIcon_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileIcon_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileIcon ((GFileIcon*) object);
  }

  auto
  FileIcon::gobj_copy () -> GFileIcon*
  {
    reference ();
    return gobj ();
  }

  FileIcon::FileIcon (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FileIcon::FileIcon (GFileIcon* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FileIcon::FileIcon (FileIcon&& src) noexcept
    : Object (std::move (src)),
      Icon (std::move (src)),
      LoadableIcon (std::move (src))
  {
  }

  auto
  FileIcon::operator= (FileIcon&& src) noexcept -> FileIcon&
  {
    Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    LoadableIcon::operator= (std::move (src));
    return *this;
  }

  FileIcon::~FileIcon () noexcept = default;

  FileIcon::CppClassType FileIcon::fileicon_class_;

  auto
  FileIcon::get_type () -> GType
  {
    return fileicon_class_.init ().get_type ();
  }

  auto
  FileIcon::get_base_type () -> GType
  {
    return g_file_icon_get_type ();
  }

  FileIcon::FileIcon ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (fileicon_class_.init ()))
  {
  }

  auto
  FileIcon::create () -> Glib::RefPtr<FileIcon>
  {
    return Glib::make_refptr_for_instance<FileIcon> (new FileIcon ());
  }

  auto
  FileIcon::get_file () -> Glib::RefPtr<File>
  {
    auto retvalue = Glib::wrap (g_file_icon_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileIcon::get_file () const -> Glib::RefPtr<const File>
  {
    return const_cast<FileIcon*> (this)->get_file ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<File>>::value,
      "Type Glib::RefPtr<File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileIcon::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<File>>
  {
    return {this, "file"};
  }

} // namespace Gio
