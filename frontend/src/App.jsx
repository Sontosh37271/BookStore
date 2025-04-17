
import './App.css'
import Courses from './components/courses/Courses.jsx'

import Home from './components/home/Home.jsx'
import {Navigate,Routes,Route} from 'react-router-dom'
import Signup from './components/Signup.jsx'
import {Toaster} from "react-hot-toast";
import { useAuth } from './context/AuthProvider.jsx'

function App() {
   const [authUser,setAuthUser] = useAuth();
   console.log(authUser);
  return (
    <>
    <div className='dark:bg-slate-900 dark:text-white'>
    <Routes>
       <Route path="/" element={<Home/>}/>
       {/* <Route path='/course' element = {authUser?<Courses/>:<Navigate to="/signup"/>}/> */}
       <Route path='/course' element = {<Courses/>}/>
       <Route path='/signup' element = {<Signup/>}/>
    </Routes>
    <Toaster/>
    </div>
    </>
  )
}

export default App
