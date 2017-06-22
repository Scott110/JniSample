package com.lib.encrypt.ndk;

/**
 * author: heshantao
 * data: 2017/6/22.
 */

public class EncryptUtile {

    public native String encrypt(String plaintext);

    public native String decrypt(String ciphertext);

    static {
        System.loadLibrary("DataLocker");
    }
}
