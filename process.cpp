


template <class T>
ImageData<T> apply_calibration(DataSpan<uint16_t, 2> raw_data,
                               DataSpan<T, 3> pedestal,
                               DataSpan<T, 3> calibration) {
    ImageData<T> img(raw_data.shape());
    for (size_t row = 0; row != raw_data.shape(0); ++row) {
        for (size_t col = 0; col != raw_data.shape(1); ++col) {
            const auto pixel = raw_data(row, col);
            const auto gain = get_gain(pixel);
            const auto adc_val = get_value(pixel);
            T val = (static_cast<T>(adcs_val) - pedestal(gain, row, col)) /
                    calibration(gain, row, col);
            img(row, col) = val;
        }
    }

    return img;
}