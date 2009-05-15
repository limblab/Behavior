using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Win32;

namespace BehaviorGraphics {
    /// <summary>
    /// Methods for setting and retrieving persistant data to the registry
    /// </summary>
    static class RegistryHelper {
        private const string REG_KEY_PATH = "Software\\Limblab\\BehaviorGraphics";
        private const string REG_KEY_LAB = "Lab";
#if DEBUG
        private const string REG_KEY_BPDIR = "LastBPDir";
        private const string REG_KEY_MODELDIR = "LastModelDir";
#else
        private const string REG_KEY_BPDIR = "LastBPDir_Debug";
        private const string REG_KEY_MODELDIR = "LastModelDir_Debug";
#endif

        /// <summary>
        /// Directory of last saved or loaded BehaviorParameters file.  Uses seperate variable for DEBUG mode.
        /// </summary>
        public static String BPDir {
            get {
                try {
                    RegistryKey key = Registry.CurrentUser.OpenSubKey(REG_KEY_PATH);
                    return (String)key.GetValue(REG_KEY_BPDIR);
                } catch (Exception) {
                    return System.Environment.CurrentDirectory;
                }
            }
            set {
                try {
                    // Try to save the last used Behavior Parameters directory
                    RegistryKey key = Registry.CurrentUser.CreateSubKey(REG_KEY_PATH);
                    key.SetValue(REG_KEY_BPDIR, value);
                } catch (Exception) { };
            }
        }

        /// <summary>
        /// Directory of last saved or loaded Model file.  Uses seperate variable for DEBUG mode.
        /// </summary>
        public static String MdlDir {
            get {
                try {
                    RegistryKey key = Registry.CurrentUser.OpenSubKey(REG_KEY_PATH);
                    return (String)key.GetValue(REG_KEY_MODELDIR);
                } catch (Exception) {
                    return System.Environment.CurrentDirectory;
                }
            }
            set {
                try {
                    // Try to save the last used Behavior Parameters directory
                    RegistryKey key = Registry.CurrentUser.CreateSubKey(REG_KEY_PATH);
                    key.SetValue(REG_KEY_MODELDIR, value);
                } catch (Exception) { };
            }
        }

        /// <summary>
        /// Lab in which the behavior is currently running.  Usefull for robot specific parameters.
        /// </summary>
        public static int Lab {
            get {
                try {
                    RegistryKey key = Registry.LocalMachine.OpenSubKey(REG_KEY_PATH);
                    String keyString = (String)key.GetValue(REG_KEY_LAB);
                    return int.Parse(keyString);
                } catch (Exception) {
                    throw new RegistryHelperException();
                }
            }
            set {
                RegistryKey key = Registry.LocalMachine.CreateSubKey(REG_KEY_PATH);
                key.SetValue(REG_KEY_LAB, value);
            }
        }

        public class RegistryHelperException : Exception { }
    }
}
