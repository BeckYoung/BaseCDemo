package com.example.basecdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.basecdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'basecdemo' library on application startup.
    static {
        System.loadLibrary("basecdemo");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
//        TextView tv = binding.sampleText;
//        tv.setText(stringFromJNI());
        //testString();
        //testVector();
        testArray();
    }

    /**
     * A native method that is implemented by the 'basecdemo' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // 测试C++中string和vector的使用
    public native void testString();
    public native void testVector();
    // 测试C++中数组的使用
    public native void testArray();
}