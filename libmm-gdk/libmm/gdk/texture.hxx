// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TEXTURE_H
#define _GDKMM_TEXTURE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkTexture = struct _GdkTexture;
using GdkTextureClass = struct _GdkTextureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Texture_Class;
}
#endif

namespace glib
{
  class LIBMM_GDK_SYMEXPORT Bytes;
}

namespace gio
{
  class LIBMM_GDK_SYMEXPORT File;
}

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Pixbuf;

  class TextureError : public glib::Error
  {
  public:
    enum Code
    {
      TOO_LARGE,
      CORRUPT_IMAGE,
      UNSUPPORTED_CONTENT,
      UNSUPPORTED_FORMAT
    };

    LIBMM_GDK_SYMEXPORT
    TextureError (Code error_code, const glib::ustring& error_message);
    LIBMM_GDK_SYMEXPORT explicit TextureError (GError* gobject);
    LIBMM_GDK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GDK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GDK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::TextureError::Code>
    : public glib::Value_Enum<gdk::TextureError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Texture : public glib::Object,
                            public Paintable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Texture;
    using CppClassType = Texture_Class;
    using BaseObjectType = GdkTexture;
    using BaseClassType = GdkTextureClass;

    Texture (const Texture&) = delete;
    auto
    operator= (const Texture&) -> Texture& = delete;

  private:
    friend class Texture_Class;
    static CppClassType texture_class_;

  protected:
    explicit Texture (const glib::ConstructParams& construct_params);
    explicit Texture (GdkTexture* castitem);

#endif

  public:
    Texture (Texture&& src) noexcept;
    auto
    operator= (Texture&& src) noexcept -> Texture&;

    ~Texture () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkTexture*
    {
      return reinterpret_cast<GdkTexture*> (gobject_);
    }

    auto
    gobj () const -> const GdkTexture*
    {
      return reinterpret_cast<GdkTexture*> (gobject_);
    }

    auto
    gobj_copy () -> GdkTexture*;

  private:
  protected:
    Texture ();

  public:
    static auto
    create_for_pixbuf (const glib::RefPtr<Pixbuf>& pixbuf)
        -> glib::RefPtr<Texture>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> glib::RefPtr<Texture>;

    static auto
    create_from_file (const glib::RefPtr<gio::File>& file)
        -> glib::RefPtr<Texture>;

    static auto
    create_from_filename (const std::string& path) -> glib::RefPtr<Texture>;

    static auto
    create_from_bytes (const glib::RefPtr<const glib::Bytes>& bytes)
        -> glib::RefPtr<Texture>;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    download (guchar* data, gsize stride) const -> void;

    auto
    save_to_png (const glib::ustring& filename) const -> bool;

    auto
    save_to_png_bytes () const -> glib::RefPtr<glib::Bytes>;

    auto
    save_to_tiff (const std::string& filename) const -> bool;

    auto
    save_to_tiff_bytes () const -> glib::RefPtr<glib::Bytes>;

    auto
    property_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkTexture* object, bool take_copy = false) -> glib::RefPtr<gdk::Texture>;
} // namespace glib

#endif
