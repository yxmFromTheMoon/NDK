package com.myron.ndklearn

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.myron.ndklearn.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val array = arrayOfNulls<Person>(10)
        for (i in 1..9) {
            array[i] = Person("test", i)
            //Log.d("test", array[i].toString())
        }
        val array2 = arrayOfNulls<Person>(10)

        arrayCopy(array,0,array2,0,10)

        for (i in 1..9) {
            Log.d("test", array2[i].toString())
        }

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
    }



    /**
     * A native method that is implemented by the 'ndklearn' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    private external fun signatureParams(): String

    companion object {
        // Used to load the 'ndklearn' library on application startup.
        init {
            System.loadLibrary("ndklearn")
        }

        external fun arrayCopy(
            src: Any, srcPos: Int, dest: Any, destPos: Int,
            length: Int
        )

        external fun signature(): String
    }
}