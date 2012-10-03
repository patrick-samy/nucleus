#include <streambuf>

namespace std
{
    // streampos
    streampos::streampos(streamoff offset)
      : offset_(offset)
    {
    }
    
    // streambuf
    streambuf::streambuf()
      : input_begin_position_(0),
        input_current_position_(0),
        input_end_position_(0),
        output_begin_position_(0),
        output_current_position_(0),
        output_end_position_(0)
    {
    }

    streambuf::streambuf(const streambuf& rhs)
      : input_begin_position_(rhs.input_begin_position_),
        input_current_position_(rhs.input_current_position_),
        input_end_position_(rhs.input_end_position_),
        output_begin_position_(rhs.output_begin_position_),
        output_current_position_(rhs.output_current_position_),
        output_end_position_(rhs.output_end_position_)
    {
    }

    streambuf::~streambuf()
    {
    }

    streambuf streambuf::operator=(const streambuf& rhs)
    {
        input_begin_position_ = rhs.input_begin_position_;
        input_current_position_ = rhs.input_current_position_;
        input_end_position_ = rhs.input_end_position_;
        output_begin_position_ = rhs.output_begin_position_;
        output_current_position_ = rhs.output_current_position_;
        output_end_position_ = rhs.output_end_position_;

        return (*this);
    }
}
