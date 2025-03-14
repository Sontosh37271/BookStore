import React from 'react'
import Navbar from '../Navbar'
import Course from '../Course'
import Footer from '../Footer'
import list from '../../../public/list.json'
export default function Courses() {
  // console.log(list);
  return (
   <>
   <Navbar/>
   <div className='min-h-screen'>
       <Course/>
   </div>
   <Footer/>
   </>
  )
}
