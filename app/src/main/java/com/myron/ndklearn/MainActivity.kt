package com.myron.ndklearn

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.myron.ndklearn.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        val list = ArrayList<Int>()
        list.add(1)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
    }

    /**
     * A native method that is implemented by the 'ndklearn' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    private external fun signatureParams():String

    companion object {
        // Used to load the 'ndklearn' library on application startup.
        init {
            System.loadLibrary("ndklearn")
        }

        external fun signature():String
    }
}