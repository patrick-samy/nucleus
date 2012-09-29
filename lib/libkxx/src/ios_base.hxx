#ifndef STD_IOS_BASE_HXX_
# define STD_IOS_BASE_HXX_

namespace std
{
	inline ios_base::fmtflags ios_base::flags() const
	{
        return format_flags_; 
	}

	inline ios_base::fmtflags ios_base::flags(ios_base::fmtflags flags)
	{
		ios_base::fmtflags old_format_flags = format_flags_;

        format_flags_ = flags;

        return old_format_flags;
	}
	
	inline ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags)
	{
        ios_base::fmtflags old_format_flags = format_flags_;

        format_flags_ |= flags;

        return old_format_flags;
	}

	inline ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags, ios_base::fmtflags mask)
	{
        ios_base::fmtflags old_format_flags = format_flags_;

        unsetf(mask);
        format_flags_ |= flags & mask;

        return old_format_flags;
	}

	inline void ios_base::unsetf(ios_base::fmtflags flags)
	{
        format_flags_ &= ~flags;
	}

    inline streamsize ios_base::precision() const
	{
        return precision_;
	}

	inline streamsize ios_base::precision(streamsize prec)
	{
        streamsize old_precision = precision_;

        precision_ = prec;

        return old_precision;
	}

	inline streamsize ios_base::width() const
	{
        return width_;
	}

	inline streamsize ios_base::width(streamsize wide)
	{
        streamsize old_width = width_;

        width_ = wide;

        return old_width;
	}
}

#endif /* !STD_IOS_BASE_HXX_ */
