// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #ifndef _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H
    #error "glibmm/variant_basictypes.h cannot be included directly"
  #endif
#endif

namespace Glib
{

  template <>
  class GLIBMM_API Variant<bool> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<bool>
    create (bool data);

    bool
    get () const;
  };

  template <>
  class GLIBMM_API Variant<unsigned char> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<unsigned char>
    create (unsigned char data);

    unsigned char
    get () const;
  };

  template <>
  class GLIBMM_API Variant<gint16> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<gint16>
    create (gint16 data);

    gint16
    get () const;
  };

  template <>
  class GLIBMM_API Variant<guint16> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<guint16>
    create (guint16 data);

    guint16
    get () const;
  };

  template <>
  class GLIBMM_API Variant<gint32> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<gint32>
    create (gint32 data);

    static Variant<gint32>
    create_handle (gint32 data);

    gint32
    get () const;
  };

  template <>
  class GLIBMM_API Variant<guint32> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<guint32>
    create (guint32 data);

    guint32
    get () const;
  };

  template <>
  class GLIBMM_API Variant<gint64> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<gint64>
    create (gint64 data);

    gint64
    get () const;
  };

  template <>
  class GLIBMM_API Variant<guint64> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<guint64>
    create (guint64 data);

    guint64
    get () const;
  };

  template <>
  class GLIBMM_API Variant<double> : public VariantBase
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

    static const VariantType&
    variant_type () G_GNUC_CONST;

    static Variant<double>
    create (double data);

    double
    get () const;
  };

} // namespace Glib
