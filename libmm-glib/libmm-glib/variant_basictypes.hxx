// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #ifndef _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H
    #error "glibmm/variant_basictypes.h cannot be included directly"
  #endif
#endif

namespace Glib
{

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<bool> : public VariantBase
  {
  public:
    using CType = gboolean;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (bool data) -> Variant<bool>;

    auto
    get () const -> bool;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<unsigned char> : public VariantBase
  {
  public:
    using CType = guchar;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (unsigned char data) -> Variant<unsigned char>;

    auto
    get () const -> unsigned char;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<gint16> : public VariantBase
  {
  public:
    using CType = gint16;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (gint16 data) -> Variant<gint16>;

    auto
    get () const -> gint16;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<guint16> : public VariantBase
  {
  public:
    using CType = guint16;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (guint16 data) -> Variant<guint16>;

    auto
    get () const -> guint16;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<gint32> : public VariantBase
  {
  public:
    using CType = gint32;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (gint32 data) -> Variant<gint32>;

    static auto
    create_handle (gint32 data) -> Variant<gint32>;

    auto
    get () const -> gint32;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<guint32> : public VariantBase
  {
  public:
    using CType = guint32;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (guint32 data) -> Variant<guint32>;

    auto
    get () const -> guint32;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<gint64> : public VariantBase
  {
  public:
    using CType = gint64;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (gint64 data) -> Variant<gint64>;

    auto
    get () const -> gint64;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<guint64> : public VariantBase
  {
  public:
    using CType = guint64;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (guint64 data) -> Variant<guint64>;

    auto
    get () const -> guint64;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<double> : public VariantBase
  {
  public:
    using CType = gdouble;

    Variant ()
      : VariantBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (double data) -> Variant<double>;

    auto
    get () const -> double;
  };

} // namespace Glib
