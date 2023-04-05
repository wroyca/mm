// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_THEMEDICON_H
#define _GIOMM_THEMEDICON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/file.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gio/loadableicon.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GThemedIcon = struct _GThemedIcon;
using GThemedIconClass = struct _GThemedIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ThemedIcon_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ThemedIcon : public glib::Object,
                               public Icon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ThemedIcon;
    using CppClassType = ThemedIcon_Class;
    using BaseObjectType = GThemedIcon;
    using BaseClassType = GThemedIconClass;

    ThemedIcon (const ThemedIcon&) = delete;
    auto
    operator= (const ThemedIcon&) -> ThemedIcon& = delete;

  private:
    friend class ThemedIcon_Class;
    static CppClassType themedicon_class_;

  protected:
    explicit ThemedIcon (const glib::ConstructParams& construct_params);
    explicit ThemedIcon (GThemedIcon* castitem);

#endif

  public:
    ThemedIcon (ThemedIcon&& src) noexcept;
    auto
    operator= (ThemedIcon&& src) noexcept -> ThemedIcon&;

    ~ThemedIcon () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GThemedIcon*
    {
      return reinterpret_cast<GThemedIcon*> (gobject_);
    }

    auto
    gobj () const -> const GThemedIcon*
    {
      return reinterpret_cast<GThemedIcon*> (gobject_);
    }

    auto
    gobj_copy () -> GThemedIcon*;

  private:
  protected:
    explicit ThemedIcon (const glib::ustring& iconname,
                         bool use_default_fallbacks = false);

    explicit ThemedIcon (const std::vector<glib::ustring>& iconnames);

  public:
    static auto
    create (const glib::ustring& iconname, bool use_default_fallbacks = false)
        -> glib::RefPtr<ThemedIcon>;

    static auto
    create (const std::vector<glib::ustring>& iconnames)
        -> glib::RefPtr<ThemedIcon>;

    auto
    prepend_name (const glib::ustring& iconname) -> void;

    auto
    append_name (const glib::ustring& iconname) -> void;

    auto
    get_names () const -> std::vector<glib::ustring>;

    auto
    property_names () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_use_default_fallbacks () const
        -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GThemedIcon* object, bool take_copy = false) -> glib::RefPtr<gio::ThemedIcon>;
} // namespace glib

#endif
