
import './App.css'
import Courses from './components/courses/Courses.jsx'

import Home from './components/home/Home.jsx'
import {Routes,Route} from 'react-router-dom'
import Signup from './components/Signup.jsx'

function App() {
 

  return (
    <>
    <div className='dark:bg-slate-900 dark:text-white'>
    <Routes>
       <Route path="/" element={<Home/>}/>
       <Route path='/course' element = {<Courses/>}/>
       <Route path='/signup' element = {<Signup/>}/>
    </Routes>
    </div>
    </>
  )
}

export default App
