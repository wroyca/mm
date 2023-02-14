
#ifndef _GTKMM_BUILDER_H
#define _GTKMM_BUILDER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gio/resource.hxx>
#include <libmm-gtk/widget.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilder = struct _GtkBuilder;
using GtkBuilderClass = struct _GtkBuilderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Builder_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Application;

  class BuilderError : public Glib::Error
  {
  public:
    enum Code
    {
      INVALID_TYPE_FUNCTION,
      UNHANDLED_TAG,
      MISSING_ATTRIBUTE,
      INVALID_ATTRIBUTE,
      INVALID_TAG,
      MISSING_PROPERTY_VALUE,
      INVALID_VALUE,
      VERSION_MISMATCH,
      DUPLICATE_ID,
      OBJECT_TYPE_REFUSED,
      TEMPLATE_MISMATCH,
      INVALID_PROPERTY,
      INVALID_SIGNAL,
      INVALID_ID,
      INVALID_FUNCTION
    };

    GTKMM_API
    BuilderError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit BuilderError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static void
    throw_func (GError* gobject);

    friend GTKMM_API void
    wrap_init ();

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::BuilderError::Code>
    : public Glib::Value_Enum<Gtk::BuilderError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API Builder : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Builder;
    using CppClassType = Builder_Class;
    using BaseObjectType = GtkBuilder;
    using BaseClassType = GtkBuilderClass;

    Builder (const Builder&) = delete;
    auto
    operator= (const Builder&) -> Builder& = delete;

  private:
    friend class Builder_Class;
    static CppClassType builder_class_;

  protected:
    explicit Builder (const Glib::ConstructParams& construct_params);
    explicit Builder (GtkBuilder* castitem);

#endif

  public:
    Builder (Builder&& src) noexcept;
    auto
    operator= (Builder&& src) noexcept -> Builder&;

    ~Builder () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBuilder*
    {
      return reinterpret_cast<GtkBuilder*> (gobject_);
    }

    auto
    gobj () const -> const GtkBuilder*
    {
      return reinterpret_cast<GtkBuilder*> (gobject_);
    }

    auto
    gobj_copy () -> GtkBuilder*;

  private:
  protected:
    Builder ();

  public:
    static auto
    create () -> Glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename) -> Glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename,
                      const Glib::ustring& object_id) -> Glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename, const char* object_id)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename,
                      const std::vector<Glib::ustring>& object_ids)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const Glib::ustring& object_id)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const char* object_id) -> Glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const std::vector<Glib::ustring>& object_ids)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_string (const Glib::ustring& buffer) -> Glib::RefPtr<Builder>;

    static auto
    create_from_string (const Glib::ustring& buffer, const char* object_id)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_string (const Glib::ustring& buffer,
                        const Glib::ustring& object_id)
        -> Glib::RefPtr<Builder>;

    static auto
    create_from_string (const Glib::ustring& buffer,
                        const std::vector<Glib::ustring>& object_ids)
        -> Glib::RefPtr<Builder>;

    auto
    add_from_file (const std::string& filename) -> bool;

    auto
    add_from_file (const std::string& filename, const char* object_id) -> bool;

    auto
    add_from_file (const std::string& filename, const Glib::ustring& object_id)
        -> bool;

    auto
    add_from_file (const std::string& filename,
                   const std::vector<Glib::ustring>& object_ids) -> bool;

    auto
    add_from_resource (const std::string& resource_path) -> bool;

    auto
    add_from_resource (const std::string& resource_path, const char* object_id)
        -> bool;

    auto
    add_from_resource (const std::string& resource_path,
                       const Glib::ustring& object_id) -> bool;

    auto
    add_from_resource (const std::string& resource_path,
                       const std::vector<Glib::ustring>& object_ids) -> bool;

    auto
    add_from_string (const Glib::ustring& buffer) -> bool;

    auto
    add_from_string (const Glib::ustring& buffer, const char* object_id)
        -> bool;

    auto
    add_from_string (const Glib::ustring& buffer,
                     const Glib::ustring& object_id) -> bool;

    auto
    add_from_string (const Glib::ustring& buffer,
                     const std::vector<Glib::ustring>& object_ids) -> bool;

    auto
    add_from_string (const char* buffer, gssize length) -> bool;

    void
    expose_object (const Glib::ustring& name,
                   const Glib::RefPtr<Glib::Object>& object);

    void
    expose_widget (const Glib::ustring& name, Widget& widget);

    auto
    get_object (const Glib::ustring& name) -> Glib::RefPtr<Glib::Object>;

    auto
    get_object (const Glib::ustring& name) const
        -> Glib::RefPtr<const Glib::Object>;

    template <class T_Object>
    inline auto
    get_object (const Glib::ustring& name) -> Glib::RefPtr<T_Object>
    {
      return std::dynamic_pointer_cast<T_Object> (get_object (name));
    }

    template <class T_Object>
    inline auto
    get_object (const Glib::ustring& name) const -> Glib::RefPtr<const T_Object>
    {
      return const_cast<Builder*> (this)->get_object<const T_Object> (name);
    }

    template <class T_Widget>
    inline auto
    get_widget (const Glib::ustring& name) -> T_Widget*
    {
      T_Widget* widget = nullptr;

      widget = dynamic_cast<T_Widget*> (
          this->get_widget_checked (name, T_Widget::get_base_type ()));

      if (!widget)
        g_critical ("Gtk::Builder::get_widget(): dynamic_cast<> failed.");

      return widget;
    }

    template <class T_Widget>
    inline auto
    get_widget (const Glib::ustring& name) const -> const T_Widget*
    {
      return const_cast<Builder*> (this)->get_widget<const T_Widget> (name);
    }

    template <typename T_Widget, typename... Args>
    inline static auto
    get_widget_derived (const Glib::RefPtr<Gtk::Builder>& builder,
                        const Glib::ustring& name,
                        Args&&... args) -> T_Widget*
    {
      using cwidget_type = typename T_Widget::BaseObjectType;
      auto pCWidget = (cwidget_type*) builder->get_cwidget (name);

      if (!pCWidget)
        return nullptr;

      T_Widget* widget = nullptr;

      Glib::ObjectBase* pObjectBase =
          ObjectBase::_get_current_wrapper ((GObject*) pCWidget);

      if (pObjectBase)
      {
        widget = dynamic_cast<T_Widget*> (Glib::wrap ((GtkWidget*) pCWidget));

        if (!widget)
          g_critical (
              "Gtk::Builder::get_widget_derived(): dynamic_cast<> failed. An "
              "existing C++ instance, of a different type, seems to exist.");
      }
      else
      {
        widget = new T_Widget (pCWidget, builder, std::forward<Args> (args)...);
      }

      return widget;
    }

    template <typename T_Widget, typename... Args>
    inline static auto
    get_widget_derived (const Glib::RefPtr<const Gtk::Builder>& builder,
                        const Glib::ustring& name,
                        Args&&... args) -> const T_Widget*
    {
      return get_widget_derived<const T_Widget> (
          std::const_pointer_cast<Gtk::Builder> (builder),
          name,
          std::forward<Args> (args)...);
    }

    auto
    get_objects () -> std::vector<Glib::RefPtr<Glib::Object>>;

    auto
    get_objects () const -> std::vector<Glib::RefPtr<const Glib::Object>>;

    void
    set_translation_domain (const Glib::ustring& domain);

    auto
    get_translation_domain () const -> Glib::ustring;

    auto
    property_translation_domain () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_translation_domain () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  protected:
    auto
    get_widget_checked (const Glib::ustring& name, GType type) -> Gtk::Widget*;
    auto
    get_cwidget (const Glib::ustring& name) -> GtkWidget*;

  private:
    bool no_gtkmm_derived_types{false};
    void
    set_no_gtkmm_derived_types (bool status);
    auto
    get_no_gtkmm_derived_types () const -> bool;
    friend class GTKMM_API Buildable_Class;
    friend class GTKMM_API BuilderScope_Class;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkBuilder* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Builder>;
} // namespace Glib

#endif
