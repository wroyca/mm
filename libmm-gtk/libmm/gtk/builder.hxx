// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUILDER_H
#define _GTKMM_BUILDER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gio/resource.hxx>
#include <libmm/gtk/widget.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilder = struct _GtkBuilder;
using GtkBuilderClass = struct _GtkBuilderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Builder_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Application;

  class BuilderError : public glib::Error
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

    LIBMM_GTK_SYMEXPORT
    BuilderError (Code error_code, const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit BuilderError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::BuilderError::Code>
    : public glib::Value_Enum<gtk::BuilderError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Builder : public glib::Object
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
    explicit Builder (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename) -> glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename,
                      const glib::ustring& object_id) -> glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename, const char* object_id)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_file (const std::string& filename,
                      const std::vector<glib::ustring>& object_ids)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const glib::ustring& object_id)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const char* object_id) -> glib::RefPtr<Builder>;

    static auto
    create_from_resource (const std::string& resource_path,
                          const std::vector<glib::ustring>& object_ids)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_string (const glib::ustring& buffer) -> glib::RefPtr<Builder>;

    static auto
    create_from_string (const glib::ustring& buffer, const char* object_id)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_string (const glib::ustring& buffer,
                        const glib::ustring& object_id)
        -> glib::RefPtr<Builder>;

    static auto
    create_from_string (const glib::ustring& buffer,
                        const std::vector<glib::ustring>& object_ids)
        -> glib::RefPtr<Builder>;

    auto
    add_from_file (const std::string& filename) -> bool;

    auto
    add_from_file (const std::string& filename, const char* object_id) -> bool;

    auto
    add_from_file (const std::string& filename, const glib::ustring& object_id)
        -> bool;

    auto
    add_from_file (const std::string& filename,
                   const std::vector<glib::ustring>& object_ids) -> bool;

    auto
    add_from_resource (const std::string& resource_path) -> bool;

    auto
    add_from_resource (const std::string& resource_path, const char* object_id)
        -> bool;

    auto
    add_from_resource (const std::string& resource_path,
                       const glib::ustring& object_id) -> bool;

    auto
    add_from_resource (const std::string& resource_path,
                       const std::vector<glib::ustring>& object_ids) -> bool;

    auto
    add_from_string (const glib::ustring& buffer) -> bool;

    auto
    add_from_string (const glib::ustring& buffer, const char* object_id)
        -> bool;

    auto
    add_from_string (const glib::ustring& buffer,
                     const glib::ustring& object_id) -> bool;

    auto
    add_from_string (const glib::ustring& buffer,
                     const std::vector<glib::ustring>& object_ids) -> bool;

    auto
    add_from_string (const char* buffer, gssize length) -> bool;

    auto
    expose_object (const glib::ustring& name,
                   const glib::RefPtr<glib::Object>& object) -> void;

    auto
    expose_widget (const glib::ustring& name, Widget& widget) -> void;

    auto
    get_object (const glib::ustring& name) -> glib::RefPtr<glib::Object>;

    auto
    get_object (const glib::ustring& name) const
        -> glib::RefPtr<const glib::Object>;

    template <class T_Object>
    inline auto
    get_object (const glib::ustring& name) -> glib::RefPtr<T_Object>
    {
      return std::dynamic_pointer_cast<T_Object> (get_object (name));
    }

    template <class T_Object>
    inline auto
    get_object (const glib::ustring& name) const -> glib::RefPtr<const T_Object>
    {
      return const_cast<Builder*> (this)->get_object<const T_Object> (name);
    }

    template <class T_Widget>
    inline auto
    get_widget (const glib::ustring& name) -> T_Widget*
    {
      T_Widget* widget = nullptr;

      widget = dynamic_cast<T_Widget*> (
          this->get_widget_checked (name, T_Widget::get_base_type ()));

      if (!widget)
        g_critical ("gtk::Builder::get_widget(): dynamic_cast<> failed.");

      return widget;
    }

    template <class T_Widget>
    inline auto
    get_widget (const glib::ustring& name) const -> const T_Widget*
    {
      return const_cast<Builder*> (this)->get_widget<const T_Widget> (name);
    }

    template <typename T_Widget, typename... Args>
    inline static auto
    get_widget_derived (const glib::RefPtr<gtk::Builder>& builder,
                        const glib::ustring& name,
                        Args&&... args) -> T_Widget*
    {
      using cwidget_type = typename T_Widget::BaseObjectType;
      auto pCWidget = (cwidget_type*) builder->get_cwidget (name);

      if (!pCWidget)
        return nullptr;

      T_Widget* widget = nullptr;

      glib::ObjectBase* pObjectBase =
          ObjectBase::_get_current_wrapper ((GObject*) pCWidget);

      if (pObjectBase)
      {
        widget = dynamic_cast<T_Widget*> (glib::wrap ((GtkWidget*) pCWidget));

        if (!widget)
          g_critical ("gtk::Builder::get_widget_derived(): dynamic_cast<> "
                      "failed. An existing C++ "
                      "instance, of a different type, seems to exist.");
      }
      else
      {
        widget = new T_Widget (pCWidget, builder, std::forward<Args> (args)...);
      }

      return widget;
    }

    template <typename T_Widget, typename... Args>
    inline static auto
    get_widget_derived (const glib::RefPtr<const gtk::Builder>& builder,
                        const glib::ustring& name,
                        Args&&... args) -> const T_Widget*
    {
      return get_widget_derived<const T_Widget> (
          std::const_pointer_cast<gtk::Builder> (builder),
          name,
          std::forward<Args> (args)...);
    }

    auto
    get_objects () -> std::vector<glib::RefPtr<glib::Object>>;

    auto
    get_objects () const -> std::vector<glib::RefPtr<const glib::Object>>;

    auto
    set_translation_domain (const glib::ustring& domain) -> void;

    auto
    get_translation_domain () const -> glib::ustring;

    auto
    property_translation_domain () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_translation_domain () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  protected:
    auto
    get_widget_checked (const glib::ustring& name, GType type) -> gtk::Widget*;
    auto
    get_cwidget (const glib::ustring& name) -> GtkWidget*;

  private:
    bool no_gtkmm_derived_types{false};
    auto
    set_no_gtkmm_derived_types (bool status) -> void;
    auto
    get_no_gtkmm_derived_types () const -> bool;
    friend class LIBMM_GTK_SYMEXPORT Buildable_Class;
    friend class LIBMM_GTK_SYMEXPORT BuilderScope_Class;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBuilder* object, bool take_copy = false) -> glib::RefPtr<gtk::Builder>;
} // namespace glib

#endif
